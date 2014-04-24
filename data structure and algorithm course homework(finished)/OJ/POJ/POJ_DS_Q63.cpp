// Try by yourself!
//
// First implement the minheap
// Then build the huffman tree
// At last answer the question
//
// 10-24: just list the frame
// 10-25: new start!

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node TreeNode;

struct Node {
	int elem;
	Node *left, *right;
};

class HuffmanTree{
public:
	TreeNode * root;

	HuffmanTree( int num );
	int ComputeWeight( TreeNode * T, int Layer );
	void PrintTree( TreeNode *T, int Layer );
	
	friend bool operator< ( const HuffmanTree &T1, const HuffmanTree &T2 );
	friend bool operator< ( const HuffmanTree &T1, const HuffmanTree &T2 );
};

bool operator< ( const HuffmanTree &T1, const HuffmanTree &T2 ){
	return (T1.root->elem < T2.root->elem);
}
bool operator> ( const HuffmanTree &T1, const HuffmanTree &T2 ){
	return (T1.root->elem > T2.root->elem);
}

HuffmanTree::HuffmanTree( int num ){
	root = ( TreeNode * ) malloc( sizeof(TreeNode) );
	root->elem = num;
	root->left = NULL;
	root->right = NULL;

}
int HuffmanTree::ComputeWeight( TreeNode * T, int Layer ){
	if( T->left == NULL && T->right == NULL )
		return Layer * T->elem;
	int left = ComputeWeight( T->left , Layer + 1 );
	int right = ComputeWeight( T->right, Layer + 1 );
	return left + right;
}
void HuffmanTree::PrintTree( TreeNode * T, int Layer ){
	if( T->left == NULL && T->right == NULL) {
		cout << T->elem << ' ' << Layer << endl;
		return ;
	}
	PrintTree( T->left, Layer + 1 );
	PrintTree( T->right, Layer + 2 );
	return ;
}

class MinHeap{
public:
	HuffmanTree *elems;
	int CurrentSize;
	int MaxSize;

	MinHeap( int size );
	inline int left( int pos );
	inline int parent( int pos );
	void SiftDown( int pos );
	void SiftUp( int pos );
	void BuildHeap();
	void InsertHuffmanTree( HuffmanTree num );
	HuffmanTree DeleteMinHuffmanTree();
	void PrintHeap(){
		for( int i = 0; i < CurrentSize; i++ ){
			cout << elems[i].root->elem <<' ';
		}
		cout << endl;
	}
};

MinHeap::MinHeap( int size ){
	elems = ( HuffmanTree * ) malloc( sizeof(HuffmanTree) * size );
	memset( elems, 0, sizeof(HuffmanTree) * size );
	MaxSize = size;
	CurrentSize = 0;
}
inline int MinHeap::left( int pos ){
	return (pos << 1) + 1;
}
inline int MinHeap::parent( int pos ){
	if( !pos ) return 0;
	if( pos % 2 == 0 ) return (pos>>1)-1;
	else return (pos>>1);
}
void MinHeap::SiftDown( int pos ){
	int i = pos;
	int j = left(pos);
	HuffmanTree tmp = elems[pos];
	while( j < CurrentSize ){
		if( j < CurrentSize - 1 && elems[j] > elems[j+1] )
			j++;
		if( tmp > elems[j] ){
			//cout << "!!!!!!!!!!!" <<endl;
			elems[i] = elems[j];
			i = j;
			j = left(j);
		}
		else 
			break;
	}
	elems[i] = tmp;
}
void MinHeap::SiftUp( int pos ){
	//cout << "-----Enter SiftUp-----" <<endl;
	int i = pos;
	int j = parent(pos);
	HuffmanTree tmp = elems[pos];
	//cout << "pos: " << i << " tmp: " << elems[pos]<<endl;
	//cout << "parent: " << j << endl;
	while( i > 0 ){
		if( j >= 0 && tmp < elems[j] ){
			elems[i] = elems[j];
			i = j;
			j = parent(j);
		}
		else break;
	}
	//cout << "last i: " << i << endl;
	elems[i] = tmp;
}

void MinHeap::BuildHeap(){
	for( int i = CurrentSize/2; i >= 0; i -- ){
		SiftDown( i );
	}
}	

void MinHeap::InsertHuffmanTree( HuffmanTree num ){
	elems[CurrentSize] = num;
	CurrentSize ++;
	SiftUp(CurrentSize-1);
}

HuffmanTree MinHeap::DeleteMinHuffmanTree(){
	HuffmanTree ret = elems[0];
	elems[0] = elems[CurrentSize-1];
	SiftDown(0);
	CurrentSize--;
	return ret;
}


HuffmanTree MergeTwoTrees( HuffmanTree &T1, HuffmanTree &T2 ){
	//cout << "----MergeTwoTrees----" << endl;
	//cout << T1.root->elem << ' ' << T2.root->elem << endl;
	HuffmanTree T( T1.root->elem + T2.root->elem );
	T.root->left = T1.root;
	T.root->right = T2.root;
	return T;
}

int main(){
	int t; cin >> t;
	while( t ){
		MinHeap heap( 10000 );
		int N; cin>>N;
		for(int i = 0; i < N; i++) {
			int num; cin>>num;
			HuffmanTree HTree( num );
			heap.InsertHuffmanTree( HTree );
			//cout << HTree.Weight << endl;
		}

		// now pull the first two out;
		while( heap.CurrentSize != 1){
			//cout << "Heap: "; heap.PrintHeap();
			HuffmanTree T1 = heap.DeleteMinHuffmanTree();
			//cout << "Heap: "; heap.PrintHeap();
			HuffmanTree T2 = heap.DeleteMinHuffmanTree();
			//cout << "Heap: "; heap.PrintHeap();

			heap.InsertHuffmanTree( MergeTwoTrees( T1, T2 ) );
		}
		HuffmanTree TNow = heap.elems[0];
		//TNow.PrintTree( TNow.root, 0 );
		cout << TNow.ComputeWeight( TNow.root, 0 )<<endl;
		t--;
	}
	return 0;
}
