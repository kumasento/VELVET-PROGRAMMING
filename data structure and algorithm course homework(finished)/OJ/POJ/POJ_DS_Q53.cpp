#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef struct Node TreeNode;

struct Node{
	int Elem;
	Node* Left;
	Node* Right;
};

TreeNode * FromMidBackBuildTree( TreeNode * T , vector<int>& MidIter, vector<int>& BackIter){
	T = new TreeNode();

	//for(int i = 0; i < MidIter.size(); i++) cout << MidIter[i] << ' ' << BackIter[i] <<endl;

	if(MidIter.size() == 1){
		T->Elem = MidIter[0];
		T->Left = NULL;
		T->Right = NULL;
		return T;
	}
	if(MidIter.size() == 0){ return NULL; }

	int RootElem = BackIter[BackIter.size()-1];
	T->Elem = RootElem;

	vector<int>::iterator MidPointer = MidIter.end(), BackPointer = BackIter.end();
	vector<int>::iterator BackEnd = BackIter.end();
	BackPointer --;
	BackEnd--;
	int j;
	for(j = MidIter.size() - 1; j >= 0 && MidIter[j] != RootElem; j--) {
		MidPointer--;
		BackPointer--; //Here is the problem!!!!!!!
	}
	vector<int> MidIterRight( MidPointer, MidIter.end() );
	MidPointer--;
	vector<int> MidIterLeft( MidIter.begin(), MidPointer );
	vector<int> BackIterLeft( BackPointer, BackEnd);
	vector<int> BackIterRight( BackIter.begin(), BackPointer );

	/*
	for(int i = 0; i < MidIterLeft.size(); i++) cout<<MidIterLeft[i]<<' ';
	cout<<endl;
	for(int i = 0; i < MidIterRight.size(); i++) cout<<MidIterRight[i]<<' ';
	cout<<endl;
	cout<<" Back "<<endl;
	for(int i = 0; i < BackIterLeft.size(); i++) cout<<BackIterLeft[i]<<' ';
	cout<<endl;
	for(int i = 0; i < BackIterRight.size(); i++) cout<<BackIterRight[i]<<' ';
	cout<<endl;
	*/

	T->Right = FromMidBackBuildTree( T->Right, MidIterRight , BackIterLeft );
	T->Left = FromMidBackBuildTree( T->Left, MidIterLeft, BackIterRight );
	return T;
}

void FrontTreeIteration( TreeNode * T ){
	if( T == NULL ) return ;
	cout<<T->Elem<<' ';
	FrontTreeIteration( T->Left );
	FrontTreeIteration( T->Right );
	return ;
}

int main(){
	// Handle input
	vector<int> TotalDataInput;
	int InputInt;
	while( cin >> InputInt )
		TotalDataInput.push_back( InputInt );
	
	int VSize = TotalDataInput.size();
	vector<int>::iterator MiddlePointer = TotalDataInput.begin();

	for(int i = 0; i < VSize/2; i++) MiddlePointer++;
	
	int TreeSize = VSize/2;
	vector<int> MidIter(TotalDataInput.begin(), MiddlePointer);
	vector<int> BackIter(MiddlePointer, TotalDataInput.end());
	
	// Start the function
	TreeNode *Tree = FromMidBackBuildTree( Tree, MidIter, BackIter );

	FrontTreeIteration( Tree );

	return 0;
}
