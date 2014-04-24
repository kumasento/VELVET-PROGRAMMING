// Find the positive circle

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 200

using namespace std;

double dis[MAXN];
int M, N, S;
double V;
struct Edge{
	int u, v; // u is the source currency, and aim is v
	double r, c; // r is rate and c is commission
} Edges[MAXN*2];

bool bellman_ford(){
	int i, j;
	memset( dis, 0, sizeof(dis) );
	dis[S] = V;

	// This loop has a restrict
	// Operation must be less than N-1 times
	// For if there's a shortest path solution
	// It must be done now
	for( i = 1; i < N; i ++ ){
		bool flag = false;
		for( j = 1; j <= 2*M; j ++ ){
			if( dis[Edges[j].v] < (dis[Edges[j].u] - Edges[j].c) * Edges[j].r ){
				dis[Edges[j].v] = (dis[Edges[j].u] - Edges[j].c) * Edges[j].r;
				flag = true;
			}
		}
		if( !flag ) // no more relax operation
			break;
	}

	// If there's no shortest path
	for( i = 1; i <= 2*M; i++ ){
		if(dis[Edges[i].v] < (dis[Edges[j].u] - Edges[j].c) * Edges[j].r)
			return true;
	}
	return false;
}

int main(){
	freopen("data2.txt", "r", stdin);
 	scanf("%d %d %d %lf", &N, &M, &S, &V);  
 	for( int i = 1; i <= M; i ++ ){
	 	scanf("%d %d", &Edges[i].u, &Edges[i].v);  
        scanf("%lf %lf", &Edges[i].r, &Edges[i].c); 
		Edges[i+M].u = Edges[i].v;
		Edges[i+M].v = Edges[i].u;
        scanf("%lf %lf", &Edges[i+M].r, &Edges[i+M].c);  
	}
	if( bellman_ford() )
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;

	return 0;
}