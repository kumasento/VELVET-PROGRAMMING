// tree-like array

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAXN 32010

using namespace std;

int C[MAXN];
inline int lowbit( int x ){ return x&(-x); }

inline int sum( int k ){
	int n = 0;
	while( k > 0 ){
		n += C[k];
		k -= lowbit(k);
	}
	return n;
}
inline void add( int x, int d, int len ){
	while( x <= len ){
		C[x] += d;
		x += lowbit(x);
	}
}

int main(){
	freopen( "data.txt", "r", stdin );

	int N; cin >> N;
	int level[N+1]; 
	memset( level, 0, sizeof(level) );
	memset( C, 0, sizeof(C) );

	for( int t = 0; t < N; t ++ ){
		int x, y;
		cin >> x >> y;
		level[sum(x+1)] += 1;
		add( x+1, 1, MAXN );
	}

	for( int i = 0; i < N; i ++ )
		cout << level[i] << endl;
	
	return 0;
}