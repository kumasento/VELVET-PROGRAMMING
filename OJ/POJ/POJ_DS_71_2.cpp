#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

#define MAXN 100
#define INF 0x3f3f3f3f

using namespace std;
int P,Q,R;
map<string,int> Addr;
map<int,string> Num;
int g[MAXN][MAXN];
int pre[MAXN];
int dist[MAXN];
int vis[MAXN];

struct cmp{
	bool operator()(int a, int b){
		return dist[a]>dist[b];
	}
};

void Dijkstra(int s){
	memset(dist, 0, sizeof(dist));
	for(int i = 1; i <= P; i++)
		if(i != s) dist[i] = INF;
	memset(pre, 0, sizeof(pre));
	memset(vis, 0, sizeof(vis));

	priority_queue<int, vector<int>, cmp> Q;
	Q.push(s); pre[s]=0;
	for(int i = 0; i < P; i++){
		int p;
		bool found = false;
		while(!Q.empty()){
			p = Q.top(); Q.pop();
			if(!vis[p]) { 
				found = true; break; 
			}
		}
		if(!found) break;
		vis[p] = 1;
		for(int j = 1; j <= P; j++){
			if(g[p][j] != -1){
				if(dist[p]+g[p][j]<dist[j]) {
					dist[j] = dist[p]+g[p][j];
					pre[j]=p;
				}
				if(!vis[j]) { Q.push(j);  }
			}
		}
	}
	return;
}
void Print(int v){
	if(!v) return;
	Print(pre[v]);
	if(pre[v])
		printf("->(%d)->", g[pre[v]][v]);
	printf("%s", Num[v].c_str());
}

int main(){
	freopen("data_71.in","r",stdin);
	scanf("%d", &P);
	for(int i = 1; i <= P; i++){ 
		string st; cin>>st;
		Addr[st] = i; Num[i] = st;
	}
	scanf("%d", &Q); 
	memset(g, -1, sizeof(g)); 
	while(Q--){
		string st1, st2; cin >> st1 >> st2;
		int w; scanf("%d", &w);
		g[Addr[st1]][Addr[st2]]=g[Addr[st2]][Addr[st1]]=w;
	}
	scanf("%d", &R);
	while(R--){
		string st1, st2; cin>>st1>>st2;
		int i = Addr[st1], j = Addr[st2];
		
		Dijkstra(i);
		Print(j);
		cout << endl;
	}	
	return 0;
}