// treap:
// I'm a fucking genius!

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int Count ;

struct Node{
	Node * ch[2];
	int r;
	char v[100];
	int cmp( char* x ) const{
		//cout << v << ' ' << x << endl;
		return (strcmp(x, v)<0) ? 0 : 1;
		// 0 is left child, 1 is right child
	};
};
inline void rotate( Node * &o, int d ){
	//Count ++;
	Node * k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o = k;
}
inline void insert( Node* &o, int r, char* v, Node * &sig ){
	Count ++;
	if( o == NULL || o == sig ){ // root 
		o = new Node( );
		o->ch[0] = o->ch[1] = NULL;
		o->r = r; 
		strcpy(o->v, v);
		return;
	}
	else{
		int d = o->cmp(v);
		//cout << d << endl;
		insert( o->ch[d], r, v, sig );
		if( o->ch[d]->r > (o->r) )
			rotate( o, d^1 );
		return ;
	}
}
inline void print( Node * o ){
	if( o == NULL ) return ;
	putchar('(');
	print(o->ch[0]);
	printf("%s/%d", o->v, o->r);
	print(o->ch[1]);
	putchar(')');
}

typedef struct _Pair{
	char v[100];
	int r;
} Pair;
int Cmp( const void * p1, const void * p2 ){
	return (( Pair * )p2)->r - (( Pair * )p1)->r;
}

int main(){
	freopen( "data.txt", "r", stdin );

	int N; cin >> N;
	while ( N ){
		Node * sig = new Node();
		Node * root = sig;

		Count = 0;

		Pair Pairs[N];
		memset( Pairs, 0, sizeof( Pairs ));
		for( int i = 0; i < N ; i++ ){
			scanf(" %[a-z]/%d", Pairs[i].v, &Pairs[i].r);
			//cout << Pairs[i].r<<endl;
			//cout << root->r << ' ' << root->v <<endl;
		}
		
		//qsort( Pairs, N, sizeof(Pair), Cmp );
		
		for( int i = 0; i < N; i++ ){
			//cout << Pairs[i].r << endl;
			insert( root, Pairs[i].r, Pairs[i].v, sig );
		}
		print( root );
		putchar('\n');
		cout << Count << endl;

		scanf("%d", &N);
	}

	return 0;
}