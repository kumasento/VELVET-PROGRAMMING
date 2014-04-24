// tel: afternoon time at esquires

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#define MAXN 10010
#define MAXS 12

using namespace std;

struct Node{
	char val;
	Node *son, *bro;
};

int ok;

void Insert( Node * &o, char* v, int i, int n ){
	if( i == n ) 
		return ;

	if( o == NULL ){
		ok = 1;
		o = new Node();
		o->val = v[i];
		o->son = o->bro = NULL;
		
		Insert( o->son, v, i+1, n );
	}
	else {
		if( o->val != v[i] )
			Insert( o->bro, v, i, n );
		else
			Insert( o->son, v, i+1, n );
	}
}

int cmp( const void *a, const void *b ){
	//char *s1 = (char*)a, *s2 = (char*)b;
	//if(strlen(s1) == strlen(s2))
	return strcmp((char*)b, (char*)a);
	//return strlen(s1) - strlen(s2);
}

int main(){
	freopen( "data.txt", "r", stdin );

	int t; cin >> t;
	while( t ){
		int N; cin >> N;
		char Data[MAXN][MAXS];
		memset( Data, 0, sizeof(Data) );

		Node * root = new Node();
		for(int i = 0; i < N; i++ )
			cin >> Data[i];

		qsort(Data, N, sizeof(Data[0]), cmp );

		for( int i = 0; i < N; i++ ){
			//cout << Data[i] <<endl;
			ok = 0;
			Insert( root, Data[i], 0, strlen(Data[i]) );
			//cout << ok << endl;
			if(!ok) 
				break;
		}
		if(!ok)
			cout << "NO"<<endl;
		else 
			cout <<"YES"<<endl;

		t--;
	}
}