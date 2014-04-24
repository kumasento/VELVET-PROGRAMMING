// This is a simple and classical implement of interval tree
// Ready to leave!
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


typedef struct Node{
	int a, b;
	long long elem;
	long long Inc;
	Node *left, *right;
} TreeNode ;

// This is my template of interval tree
class IntervalTree{
public:
	TreeNode * root;

	IntervalTree( int a, int b );
	int BuildIntervalTree( TreeNode * T, int a, int b ); // The elem's initialization?
	long long AssignElement( TreeNode * T, int *elems );
	long long PrintIntervalValue( TreeNode * T, int a, int b, long long Inc );
	void AddValue( TreeNode *T, int a, int b, long long v );
	void PrintIntervalTree( TreeNode * T );
};

void IntervalTree::PrintIntervalTree( TreeNode * T ){
	if( T == NULL ) return ;
	cout << T->a << ' ' << T->b << ' ' << ' ' << T->elem << ' ' << T->Inc << endl;
	PrintIntervalTree( T->left );
	PrintIntervalTree( T->right );
	return ;
}

// root is the full interval
IntervalTree::IntervalTree( int a, int b ){
	root = (TreeNode*) malloc( sizeof( TreeNode ) );
	BuildIntervalTree( root, a, b );
}
// IntervalTree.BuildIntervalTree( IntervalTree.root )
int IntervalTree::BuildIntervalTree( TreeNode * T, int a, int b ){
	// left is [a,(a+b)/2]
	// right is [(a+b)/2+1,b]
	T->a = a; T->b = b;
	T->Inc = 0;

	if( a == b ) { return a; }

	T->left = ( TreeNode * ) malloc( sizeof( TreeNode ) );
	T->right = ( TreeNode * ) malloc( sizeof( TreeNode ) );
	memset( T->left, 0, sizeof( TreeNode ) );
	memset( T->right, 0, sizeof( TreeNode ) );

	BuildIntervalTree( T->left, a, (a+b)/2 );
	BuildIntervalTree( T->right, (a+b)/2+1, b );
	return a;
}
// assign the elem's value
long long IntervalTree::AssignElement( TreeNode * T, int * elems ){
	if( T->a == T->b ){
		T->elem = elems[T->a-1];
		return T->elem;
	}
	long long l = AssignElement( T->left, elems );
	long long r = AssignElement( T->right, elems );
	T->elem = l + r; 
	return T->elem;
}
// print answer
long long IntervalTree::PrintIntervalValue( TreeNode * T, int a, int b, long long Inc ){
	if( T->a == a && T->b == b ) {
		//T->Inc = ( T->Inc ) ? T->Inc : Inc;
		return T->elem+T->Inc*(T->b-T->a+1);
	}
	int mid = ( T->a + T->b ) /2;

	// assign the next layer's Inc value
	(T->left)->Inc += T->Inc; 
	(T->right)->Inc += T->Inc;	
	// clear the current layer's value
	T->elem = T->Inc*(T->b-T->a+1) + T->elem;
	T->Inc = 0;

	long long l = 0, r = 0;
	if( a <= mid ){
		if( b <= mid )
			l = PrintIntervalValue( T->left, a, b, Inc );
		else{
			l = PrintIntervalValue( T->left, a, mid, Inc );
			r = PrintIntervalValue( T->right, mid+1, b, Inc );
		}
	}
	else 
		r = PrintIntervalValue( T->right, a, b, Inc );
	
	// return value is not the T->elem
	return l+r;
}
// add value
void IntervalTree::AddValue( TreeNode * T, int a, int b, long long v ){
	// ??????
	// If the [a,b] can exactly cover:
	if( a == T->a && T->b == b ){
		T->Inc += v;
		return ;
	}

	// or not?
	// transcend the addvalue down
	T->elem += v * (b-a+1);
	int mid = (T->a + T->b)/2;
	if( a <= mid ){
		if( b <= mid )
			AddValue( T->left , a, b, v );
		else{
			AddValue( T->left, a, mid, v );
			AddValue( T->right, mid+1, b, v );
		}
	}
	else 
		AddValue( T->right, a, b, v );
	return ;
}

int main(){
	int N, Q; cin>>N>>Q;
	int elems[N];
	for( int i = 0; i < N; i++ ) cin>>elems[i];
	IntervalTree ITree(1, N);
	ITree.AssignElement( ITree.root, elems );
	for( int i = 0; i < Q; i++ ){
		string type; cin>>type;
		if( type[0] == 'Q' ){
			int a, b; cin>>a>>b;
			cout << ITree.PrintIntervalValue( ITree.root, a, b, 0 ) << endl;
		}
		else if ( type[0] == 'C' ){
			int a, b, c;
			cin>>a>>b>>c;
			ITree.AddValue( ITree.root, a, b, c );
		}
		ITree.PrintIntervalTree( ITree.root );
	}

	return 0;
}
