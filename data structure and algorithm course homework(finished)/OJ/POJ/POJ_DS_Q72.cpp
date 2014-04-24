// simple implementation of kruskal

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define MAXN 1000
#define D 500

using namespace std;

struct _e{
	int u, v;
	int w;
} e[MAXN];

int cmp( const void *a, const void *b ){
	struct _e * e1 =(struct _e *) a, *e2 =(struct _e *) b;
	return (e1->w - e2->w);
}

int N;
int set[MAXN];

int Find( int v ){
	while( set[v] != v ){
		v = set[v];
	}
	return v;
}
void Union( int u, int v ){
	int r1 = Find(u), r2 = Find(v);
	set[r2] = r1;
	return ;
}

int main(){
	freopen( "data.txt", "r", stdin );

	// manipulate the route data
	int n; cin >> n;
	int index = 0;
	for( int i = 0; i < n-1; i ++ ){
		char ch; cin >> ch; int u = ch-'A'; 
		int k; cin >> k;
		for( int j = 0; j < k; j++ ){
			cin >> ch; int v = ch-'A';
			e[index].u = u; e[index].v = v; cin >> e[index].w;
			index ++;
			e[index].u = v; e[index].v = u; e[index].w = e[index-1].w;
			index ++;
		}
	}

	N = index;
	qsort( e, N, sizeof(e[0]), cmp);
	//for( int i = 0; i < N; i++ ) 	printf("%c %c %d\n", e[i].u+'A', e[i].v+'A', e[i].w);
	memset( set, 0, sizeof(set) );
	for( int i = 0; i < n; i++ )
		set[i] = i;

	int count = 0;
	index = 0;
	int sum = 0;
	while( count < n-1 ){
		while(Find(e[index].u) == Find(e[index].v))
			index++;
		sum += e[index].w;
		Union(e[index].u, e[index].v);
		count++;
	}

	cout << sum << endl;

	return 0;
}