#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 10010
#define lson l , m , rt << 1    
#define rson m + 1 , r , rt << 1 | 1 

using namespace std;

int ln[MAXN], rn[MAXN];
int X[MAXN*3];
int A[MAXN<<4];
int cnt;
bool Hash[MAXN];

int cmp( const void * a, const void * b ){
	return *((int *) a) - *((int *) b);
}
int binary( int key, int n ){
	int l = 0, r = n - 1;
	while( l <= r ){
		int mid = (l+r)>>1;
		if(X[mid] == key) return mid;
		if(X[mid] < key) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
void PushDown( int o ){
	if( A[o] != -1 ){ // it has a signal
		A[o<<1] = A[o<<1|1] = A[o]; //set it's children
		A[o] = -1; // return to -1;
	}
}
void Update( int L, int R, int c, int l, int r, int rt ){
	if( L <= l && R >= r ){ // can be covered
		A[rt] = c;
		return ;
	}
	PushDown( rt );
	int m = ( l+r ) >> 1;
	if( L <= m ) Update( L, R, c, lson );
	if( m < R ) Update( L, R, c, rson );
}
void Query( int l, int r, int rt ){
	if( A[rt] != -1 ){
		if( !Hash[A[rt]] ) cnt ++;
		Hash[A[rt]] = true;
		return ;
	}
	if( l == r ) return;
	int m = ( l + r )>>1;
	Query( lson );
	Query( rson );
}

int main(){
	freopen( "data2.txt", "r", stdin );

	int t;
	scanf( "%d", &t );
	while( t ){
		int n; scanf("%d", &n);
		int nn = 0;
		for( int i = 0; i < n; i ++ ){
			scanf( "%d%d", &ln[i], &rn[i]);
			X[nn++] = ln[i]; X[nn++] = rn[i];
		}
		qsort( X, nn, sizeof(int), cmp );

		// abort the same ones
		int k = 1;
		for( int i = 1; i < nn; i ++ ){
			if( X[i-1] != X[i] )
				X[k++] = X[i]; 
		}

		nn = k;

		// calculate the real border
		for( int i = 0; i < nn - 1; i ++ ){
			if( X[i+1] > X[i]+1 )
				X[k++] = X[i]+1;
		}
		qsort( X, k, sizeof(int), cmp );
		memset( A, -1, sizeof(A) );

		for( int i = 0; i < n; i ++ ){
			int l = binary( ln[i], k );
			int r = binary( rn[i], k );
			//cout << ln[i] << ' ' << l << endl;
			//cout << rn[i] << ' ' << r << endl;
			Update( l, r, i, 0, k, 1 );
		}
		cnt = 0;    
        memset(Hash , false , sizeof(Hash));   //Hash store the value of is_covered 
        Query( 0, k, 1 );
        printf( "%d\n", cnt );
		t--;
	}
	return 0;
}