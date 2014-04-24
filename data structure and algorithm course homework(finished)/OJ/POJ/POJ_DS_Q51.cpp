#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node TreeNode;

struct Node{
	int Elem;
	Node * Left;
	Node * Right;
};

TreeNode * FindTreeNodeById( TreeNode * Tree, int tid ){
	if( Tree == NULL ) return NULL;
	if( Tree->Elem == tid ) return Tree;
	
	TreeNode * l_res, * r_res;
	l_res = FindTreeNodeById( Tree->Left, tid );
	if( l_res != NULL ) return l_res;
	r_res = FindTreeNodeById( Tree->Right, tid );
	return r_res;
}

vector<TreeNode *> NodeStorage(100);

void InsertTree( TreeNode * Tree, int tid, int l_tid, int r_tid ){
	TreeNode *T = FindTreeNodeById( Tree, tid );
	int ok = 1;
	if( T == NULL ){
		ok = 0;
		T = new TreeNode();
		T->Elem = tid;
	}
	if(l_tid != -1){
		if(NodeStorage[l_tid] != NULL)
			T->Left = NodeStorage[l_tid];	
		else{
			T->Left = new TreeNode();
			T->Left->Elem = l_tid;
			T->Left->Left = T->Left->Right = NULL;
		}
	}
	if(r_tid != -1){
		if(NodeStorage[r_tid] != NULL)
			T->Right = NodeStorage[r_tid];
		else{
			T->Right = new TreeNode();
			T->Right->Elem = r_tid;
			T->Right->Left = T->Right->Right = NULL;
		}
	}
	if(!ok) 
		NodeStorage[T->Elem] = T;
}

TreeNode * FindTreeNodeBySon( TreeNode * T, int sid, bool isLeft ){
	if( T == NULL ) 
		return NULL;
	if( isLeft && T->Left != NULL && (T->Left)->Elem == sid )
		return T;
	if( !isLeft && T->Right != NULL && (T->Right)->Elem == sid )
		return T;
	
	TreeNode * l_ans, * r_ans;
	l_ans = FindTreeNodeBySon( T->Left, sid, isLeft );
	r_ans = FindTreeNodeBySon( T->Right, sid, isLeft );
	
	return ( l_ans == NULL ) ? r_ans : l_ans;
}

void SwitchTreeNode( TreeNode * T, int l_tid, int r_tid ){
	TreeNode *l_T, *r_T;
	bool l_isLeft = true, r_isLeft = true;
	
	l_T = FindTreeNodeBySon( T, l_tid, l_isLeft );
	if(l_T == NULL){
		l_isLeft = !l_isLeft;
		l_T = FindTreeNodeBySon( T, l_tid, l_isLeft );
	}
	
	r_T = FindTreeNodeBySon( T, r_tid, r_isLeft );
	if( r_T == NULL ){
		r_isLeft = !r_isLeft;
		r_T = FindTreeNodeBySon( T, r_tid, r_isLeft);
	}

	TreeNode *l_N = (l_isLeft) ? l_T->Left : l_T->Right;
	TreeNode *r_N = (r_isLeft) ? r_T->Left : r_T->Right;
	
	if(l_isLeft) l_T->Left = r_N; 
	else l_T->Right = r_N;

	if(r_isLeft) r_T->Left = l_N;
	else r_T->Right = l_N;

}

void FindLeftMostSon( TreeNode *Tree, int tid ){
	TreeNode * T = FindTreeNodeById( Tree, tid );
	while( T->Left != NULL ) T = T->Left;
	cout<<T->Elem<<endl;
}

int main(){
	int N; cin>>N;
	while( N ){
		int m, n; cin >> n >> m;
		
		TreeNode * Tree = new TreeNode();
		Tree->Elem = 0;
		Tree->Left = Tree->Right = NULL;
		
		while( n ){
			int X, Y, Z; cin >> X >> Y >> Z;
			InsertTree( Tree, X, Y, Z );
			n--;
		}
		while( m ){
			int type; cin >> type;
			if( type == 1 ){
				int x, y; cin >> x >> y;
				SwitchTreeNode( Tree, x, y );
			}
			
			else if( type == 2){
				int x; cin >> x;
				FindLeftMostSon( Tree, x );
			}
			m --;
		}

		N--;
	}

	return 0;
}
