/*
Question Understanding:
2-machine scheduling
A, B, n, m working_modes
how to translate the question in to match problem?
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAXN 200

using namespace std;

int g[MAXN][MAXN];
int linker[MAXN];
int used[MAXN];
int uN, vN;

bool dfs(int u){
	int v;
	for( v=0; v<vN; v++ ){
		if(g[u][v] && !used[v]){
			used[v] = true;
			if(linker[v]==-1 || dfs(linker[v])){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int u; int res = 0;
	memset(linker,-1,sizeof(linker));
	for( u = 0; u<uN; u++ ){
		memset(used,0,sizeof(used));
		if(dfs(u))
			res++;
	}
	return res;
}

int main(){
	freopen("data_q52.in","r",stdin);
	int t; cin >> t;
	while( t ){
		uN = t; cin >> vN;
		int k; cin >> k;
		memset(g,0,sizeof(g));
		for(int i = 0; i < k; i++){
			int x, y, id; cin>>id>>x>>y;
			g[x-1][y-1] = 1;
		}
		cout << hungary() << endl;
		cin >> t;
	}

	return 0;
}