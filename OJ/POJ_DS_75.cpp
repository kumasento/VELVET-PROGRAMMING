#include <iostream>
#include <cstring>  
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

#define MAXN 100

using namespace std;

int g[MAXN][MAXN];
int vis[MAXN];
int v, a;

int main(){
	freopen("data_75.in","r",stdin);
	scanf("%d%d", &v, &a);
	memset(g, 0, sizeof(g));
	while(a--){ 
		int x, y; 
		scanf("%d%d", &x, &y);
		g[x][y] = 1; 
	}
	memset(vis, 0, sizeof(vis));
	int T = 0;
	while( T < v ){
		for(int i = 1; i <= v; i++){
			if(!vis[i]){
				int cnt = 0; 
				for(int j = 1; j <= v; j++)
					if(g[j][i]) cnt++;
				if(!cnt){ 
					vis[i]=1;  
					for(int j = 1; j <= v; j++) g[i][j] = 0;
					printf("v%d ", i);
					T++;
					break;
				}
			}
		}
	}
	cout << endl;

	return 0;
}