// nice noon

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <queue>
#include <stack>
#include <vector>

#define MAXN 100000

struct Edge{
	int u, v;
	int w;
};
int cmp( const void *a, const void *b ){
	return ((Edge*)a)->w - ((Edge*)b)->w;
}

Edge Edges[MAXN];

using namespace std;

int main(){
	freopen( "data.txt", "r", stdin );
	int n; cin >> n;
	int k = 0;
	memset( Edges, 0, sizeof(Edges) );
	for( int i = 0; i < n-1; i ++ ){
		string ch; cin >> ch;
		int N; cin >> N;
		for( int j = 0; j < N; j ++ ){
			string cc; cin >> cc;
			int w; cin >> w;

			Edges[k].u = ch[0]-'A';
			Edges[k].v = cc[0]-'A';
			Edges[k].w = w;

			k++;
		}
	}
	qsort( Edges, k, sizeof(Edge), cmp );
	/*
	for( int i = 0; i < k-1; i ++ ){
		printf("%d %d %d\n", Edges[i].u, Edges[i].v, Edges[i].w);
	}
	*/
	int ufs[n];
	memset( ufs, 0, sizeof(ufs) );

	vector<int> MST;
	for( int i = 0; i < n; i ++ )
		ufs[i] = i;
	int nn = 0, i = 0, sum = 0;
	while( i < n-1 ){
		while( ufs[Edges[nn].u] == ufs[Edges[nn].v] ) nn++;
		int u = ufs[Edges[nn].u], v = ufs[Edges[nn].v];
		int min = (u<v) ? Edges[nn].u : Edges[nn].v;
		int max = (u>v) ? Edges[nn].u : Edges[nn].v;
		ufs[min] = ufs[max];
		sum += Edges[nn].w;
		i++;
	}
	cout << sum << endl;
	return 0;
}