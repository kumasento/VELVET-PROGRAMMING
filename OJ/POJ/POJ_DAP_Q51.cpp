#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAXN 500

int g[MAXN][MAXN];
int linker[MAXN];
int used[MAXN];
int uN, vN;

bool dfs( int u ){
	int v;
	for( v = 0; v < vN; v++ ){
		if( g[u][v] && !used[v] ){
			used[v] = true;
			if( linker[v] == -1 || dfs(linker[v]) ){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	int res = 0;
	int u;
	memset( linker, -1, sizeof(linker) );
	for( u = 0; u < uN; u++ ){
		memset( used, 0, sizeof(used) );
		if(dfs(u))
			res++;
	}
	return res;
}

int main(){
	freopen("data_q51.in","r",stdin);
	int T; cin >> T;
	while( T-- ){
		memset(g,0,sizeof(g));
		cin >> vN >> uN;
		for( int k = 0; k < vN; k++ ){
			int n; cin >> n;
			for( int i = 0; i < n; i++ ){
				int t; cin >> t;
				g[t-1][k] = 1;
			}
		}
		int res = hungary();
		//cout << res << endl;
		if(res != vN)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
}