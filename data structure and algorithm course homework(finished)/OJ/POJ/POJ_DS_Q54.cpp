// Build a binary tree from infix expression
//
// Nice noon!
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	char Elem;
	Node* Left;
	Node* Right;
	int Bias;
	int Layer;
	int Num;
} TreeNode;

TreeNode* Tree;
int TreeHeight;

int InsertExpTree(char Elem, TreeNode* T, int layer, int *ParaNum){
	if( T->Elem == 0  ){
		T->Elem = Elem;
		T->Num = ParaNum[Elem-'a'];
		T->Layer = layer;
		if(T->Layer > TreeHeight) 
			TreeHeight = T->Layer;

		T->Left = (TreeNode *) malloc( sizeof( TreeNode ) );
		memset(T->Left, 0, sizeof( TreeNode ));
		T->Right = (TreeNode *) malloc( sizeof( TreeNode ) );
		memset(T->Right, 0, sizeof( TreeNode ) );
		return 1;
	}
	else {
		int tright = (T->Right)->Elem - 'a';
		int tleft = (T->Left)->Elem - 'a';
		if( !(tright>=0 && tright<=25) && InsertExpTree( Elem, T->Right, layer + 1, ParaNum ) )
			return 1;
		if( !(tleft>=0 && tleft<=25) && InsertExpTree( Elem, T->Left, layer + 1, ParaNum ) )
			return 1;
		return 0;
	}
}

int BottomPosition;

int CalTreePosition( TreeNode *T ){
	if(T->Layer == TreeHeight){
		BottomPosition += 2;
		T->Bias = BottomPosition;
	}
	else {
		int l_pos, r_pos;
		TreeNode* l_p = T->Left, *r_p = T->Right;
		if(l_p->Elem == 0){
			//If it's not full, just add ' ' as its son

			l_p->Left = (TreeNode *) malloc( sizeof( TreeNode ) );
			l_p->Right = (TreeNode *) malloc( sizeof( TreeNode ) );
			memset(l_p->Left,0,sizeof(TreeNode));
			memset(l_p->Right, 0, sizeof(TreeNode));
			
			r_p->Left = (TreeNode *) malloc( sizeof( TreeNode ) );
			r_p->Right = (TreeNode *) malloc( sizeof( TreeNode ) );
			memset(r_p->Right, 0, sizeof( TreeNode ) );
			memset(r_p->Left, 0, sizeof( TreeNode ) );

			l_p->Elem = r_p->Elem = ' ';
			l_p->Layer = r_p->Layer = T->Layer + 1;
		}

		l_pos = CalTreePosition( l_p );
		r_pos = CalTreePosition( r_p );

		T->Bias = (l_pos + r_pos) / 2;
	}
	return T->Bias;
}

void ShowExpTree( TreeNode *T){
	queue<TreeNode *> BfsQueue;
	BfsQueue.push(T);
	
	queue<int> PosQueue;
	
	TreeNode* pointer = T;
	int layer = 0, i = 0;
	
	while(!BfsQueue.empty()){
		pointer = BfsQueue.front();
		BfsQueue.pop();
	
		if(pointer->Layer > layer){
			i = 0;
			layer ++; cout<<endl;
			int j = 0;
			while( !PosQueue.empty() ){
				int bias = PosQueue.front();
				PosQueue.pop();
				
				while( j < bias-1 ) { cout<<' '; j++; }
				cout<<"/ \\";
				j += 3;
			}
			cout<<endl;
		}

		for(; i < pointer->Bias; i++) cout<<' ';
		cout<<pointer->Elem;
		i++;
		if( (pointer->Left)->Elem != 0 )
			BfsQueue.push(pointer->Left);
		if( (pointer->Right)->Elem != 0 )
			BfsQueue.push(pointer->Right);

		if(!(pointer->Left->Elem == ' ' && pointer->Right->Elem == ' ' ) ) 
			PosQueue.push( pointer->Bias );
	}

}

int cal(int op1, int op2, char operand){
	switch(operand){
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

int CalExpAnswer(TreeNode * T, int * ParaNum){
	char Elem = T->Elem;
	int Get = Elem - 'a';
	if(Get >= 0 && Get <= 25) return ParaNum[Get];
	if(Get == ' '-'a') return 0;
	int op1 = CalExpAnswer( T->Left, ParaNum );
	int op2 = CalExpAnswer( T->Right, ParaNum );
	return cal(op1, op2, Elem);
}

int main(){
	string str; cin >> str;
	int N; cin >> N;
	
	// if u wanna get 'a' value, do ParaNum['a'-'a'];
	int ParaNum[100]; memset(ParaNum, 0, sizeof(ParaNum));
	while(N){
		char Para; cin >> Para;
		cin >> ParaNum[Para-'a'];
		N--;
	}
	// Input Finished;
	
	// Build Prior Map
	map<char, int> PriorityMap;
	PriorityMap.insert(pair<char, int>('+', 1));
	PriorityMap.insert(pair<char, int>('-', 1));
	PriorityMap.insert(pair<char, int>('*', 2));
	PriorityMap.insert(pair<char, int>('/', 2));
	PriorityMap.insert(pair<char, int>('(', 3));

	stack<char> SuffixStack, OperandStack; 
	for(int i = 0; i < str.length(); i++){
		char Getc = str[i];
		int Getn = Getc - 'a';
		
		if( Getn >= 0 && Getn <= 25 ){ SuffixStack.push(Getc); }
		else{
			if(Getc == ')'){
				while(!OperandStack.empty()){
					if(OperandStack.top() == '('){
						OperandStack.pop();
						break;
					}
					else {
						char operand = OperandStack.top();
						OperandStack.pop();
						SuffixStack.push(operand);
					}
				}
			}
			else{
				while(!OperandStack.empty()){
					char TopOperand = OperandStack.top();
					if(PriorityMap[TopOperand] >= PriorityMap[Getc] && TopOperand != '('){
						OperandStack.pop();
						SuffixStack.push(TopOperand);
					}
					else break;
				}
				OperandStack.push(Getc);
			}		
		}
	}
	while(!OperandStack.empty()){
		SuffixStack.push(OperandStack.top());
		OperandStack.pop();
	}
	stack<char> OutputStack;
	while(!SuffixStack.empty()){
		OutputStack.push(SuffixStack.top());
		SuffixStack.pop();
	}

	while(!OutputStack.empty()){
		cout<<OutputStack.top();
		SuffixStack.push(OutputStack.top());
		OutputStack.pop();
	}
	
	cout<<endl;
	
	//Now Build the binary tree;
	Tree = (TreeNode *) malloc( sizeof( TreeNode ) );
	memset( Tree, 0, sizeof( TreeNode ) );
	TreeHeight = 0;

	while(!SuffixStack.empty()){
		char Top = SuffixStack.top();
		SuffixStack.pop();
		InsertExpTree( Top, Tree, 0, ParaNum );
	}
	
	BottomPosition = -2;	
	CalTreePosition( Tree );

	ShowExpTree( Tree );
	
	cout<<endl;
	cout<<CalExpAnswer( Tree, ParaNum );
	return 0;
}
