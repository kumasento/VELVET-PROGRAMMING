#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cmath>

#define N 1000
#define M 100000

using namespace std;

struct coord{ double x, y; } v[N];
struct edge{ int u, v; double w; } e[M];

int pre[N]; // store the order of the MST
int hashl[N]; // store the circle connection
int vis[N]; // store if visited
double In[N];

double D_MST(int root, int n, int m){
	double ret = 0;
	while(true){ //enter the loop
		for( int i = 0; i < n; i++ )
			In[i] = INT_MAX; // init In[]
		for( int i = 0; i < m; i++ ){ // find the smallest in edge
			int u = e[i].u;
			int v = e[i].v;
			if(e[i].w < In[v] && u!=v){
				In[v] = e[i].w;
				pre[v] = u;
			}
		}

		// find if MST could be built
		for( int i = 0; i < n; i ++ ){
			if( i == root )
				continue;
			if( In[i] == INT_MAX)
				return -1; // if the graph cant be connected
		}

		// prepare for finding circles
		int cnt = 0; // get the circle number;
		memset( hashl, -1, sizeof( hashl ));
		memset( vis, -1, sizeof( vis ));
		In[root] = 0;

		for( int i = 0; i < n; i++ ){
			ret += In[i];
			int v = i; // to find circle start from i
			while( vis[v] != i && hashl[v] == -1 && v != root ){
				vis[i] = i;
				v = pre[v];
			}
			if( v != root && hashl[v] == -1){
				for( int u = pre[v] ; u != v; u = pre[u] )
					hashl[u] = cnt;
				hashl[v] = cnt ++;
			}
		}
		if(cnt == 0) // no circle here
			break;
		for( int i = 0; i < n; i ++ ) // add the single point
			if(hashl[i] == -1)
				hashl[i] = cnt++;
		for( int i = 0; i < m; i++ ){ // remark
			int v = e[i].v;
			e[i].u = hashl[e[i].u];
			e[i].v = hashl[e[i].v];
			if(e[i].u != e[i].v)
				e[i].w -= In[v];
		}
			
		n = cnt;
		root = hashl[root];
	}
	return ret;

};

int main(){
	freopen("data_Q84.in", "r", stdin);
	int n, m; 	
	while(cin >> n >> m){
		memset( v, 0, sizeof(v) );
		memset( e, 0, sizeof(e) );

		for( int i = 0; i < n; i++ )
			scanf("%lf%lf", &v[i].x,&v[i].y);
		int mm = 0;
		for( int i = 0; i < m; i++ ){
			int a, b;
			scanf("%d%d", &a, &b);
			if(a==b) continue;
			a--; b--;
			e[mm].u = a; e[mm].v = b;
			e[mm].w = sqrt(pow((v[e[mm].u].x-v[e[mm].v].x),2)
				+pow((v[e[mm].v].y-v[e[mm].v].y),2));
			mm++;
			cout << e[mm-1].w <<endl;
		}

		//cout << 1 << endl;
		double ans = D_MST(0,n,mm);
		if(ans == -1)
			cout << "NO" << endl;
		else 
			printf("%.2f\n", ans);
	}

	return 0;
}
