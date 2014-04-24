// No dota anymore!
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


class TreeNode{
public:
	int elem;
	int isNull;
	TreeNode *left, *right;
};

void FindBST( TreeNode *T, int elem );
void PrintBST( TreeNode *T );

int main(){
	TreeNode * Tree = new TreeNode();
	Tree->isNull = 1;
		
	int input;
	while( cin >> input ){
		FindBST( Tree, input );
	}
	PrintBST( Tree );

	return 0;
}

void FindBST( TreeNode *T, int elem ){
	if( T->elem == elem ) return ;
	if( T->isNull == 1 ){
		T->elem = elem;
		T->isNull = 0;
		T->left = new TreeNode();
		T->right = new TreeNode();
		T->left->isNull = T->right->isNull = 1;
		return ;
	}
	if( elem < T->elem ) FindBST( T->left, elem );
	else FindBST( T->right, elem );
}

void PrintBST( TreeNode *T ){
	if( T->isNull == 1 ) return;
	cout << T->elem <<' ';
	PrintBST( T->left );
	PrintBST( T->right );
}
