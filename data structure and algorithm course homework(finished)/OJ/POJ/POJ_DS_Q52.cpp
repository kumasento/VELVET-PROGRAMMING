//Test BinaryTree
//
//I can't finish my homework!!!
//
//It's a binary tree impletation
//
//Not only a impletation, can simplify it to a preorder question
//order + layer can return to a tree
//
//you need a global char because sometimes you need to get and reuse the value

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct Node {
	char Elem;
	Node *Left, *Right;
};
typedef struct Node TreeNode;
TreeNode * Tree;

char LayerControl[20];

int InsertElem( int layer, char Elem, int ltmp, TreeNode * T ){
	// one layer lower 
	if( ltmp <= layer - 1 ){
		if( T->Elem != LayerControl[ltmp] ) return 0;
		if( (T->Left)->Elem != '*' && InsertElem( layer, Elem, ltmp + 1, T->Left ) == 1 )
			return 1;
		if( (T->Right)->Elem != '*' && InsertElem( layer, Elem, ltmp + 1, T->Right ) == 1 )
			return 1;
		return 0;
	}
	else if ( ltmp == layer ){
		if( T->Elem == 0 ){
			T->Elem = Elem;
			T->Left = (TreeNode *) malloc( sizeof( TreeNode ) );
			memset(T->Left, 0, sizeof( TreeNode ) );
			T->Right = (TreeNode *) malloc( sizeof( TreeNode ) );
			memset(T->Right, 0, sizeof( TreeNode ) );
			return 1;
		}
		else 
			return 0;
	}
};

void PreOrderPrint(int layer, TreeNode * T){
	if( T->Elem != 0 ){
		if( T->Elem != '*' ) cout<<T->Elem;
		PreOrderPrint(layer+1, T->Left);
		PreOrderPrint(layer+1, T->Right);
	}
}

void SufOrderPrint(int layer, TreeNode *T){
	if( T->Elem != 0 ){
		if( T->Elem != '*' ){
			SufOrderPrint(layer+1, T->Left);
			SufOrderPrint(layer+1, T->Right);
			cout<<T->Elem;
		}
	}
}

void MidOrderPrint(int layer, TreeNode *T){
	if( T->Elem != 0 ){
		if( T->Elem != '*' ){
			MidOrderPrint(layer+1, T->Left);
			cout<<T->Elem;
			MidOrderPrint(layer+1, T->Right);
		}
	}	
}

int main(){
	int N; cin >> N;
	
	while(N){
		memset(LayerControl, 0, sizeof( LayerControl ) );
		string in; cin>>in;
		Tree = (TreeNode *) malloc( sizeof( TreeNode ) );
		memset(Tree, 0, sizeof( TreeNode ) );
		while(!(in[0] == '0' && in.length() == 1)){ 
			int layer = 0;
			while( in[layer] == '-' ) layer ++;
			LayerControl[layer] = in[layer];
			InsertElem( layer, in[layer], 0, Tree );
			cin>>in;
		}

		PreOrderPrint( 0, Tree );
		cout<<endl;
		SufOrderPrint( 9, Tree );
		cout<<endl;
		MidOrderPrint( 0, Tree );
        cout<<endl;
		N--;
		cout<<endl;
	}
	return 0;
}
