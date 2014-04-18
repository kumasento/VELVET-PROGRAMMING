#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>

#define MAXN 100
#define INF 0x3f3f3f3f

using namespace std;
int P,Q,R;
map<string,int> Addr;
map<int,string> Num;
int g[MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
int path[MAXN][MAXN];

void Floyd(){
	for(int i = 1; i <= P; i++){
		for(int j = 1; j <= P; j++){
			if(i != j && g[i][j] != -1)
				f[i][j][0] = g[i][j];
			else
				f[i][j][0] = (i==j)?0:INF;
		}
	}
	for(int k = 1; k <= P; k++){
		for(int i = 1; i <= P; i++){
			for(int j = 1; j <= P; j++){
				f[i][j][k] = f[i][j][k-1];
				if(f[i][k][k-1]+f[k][j][k-1]<f[i][j][k]){
					f[i][j][k] = f[i][k][k-1]+f[k][j][k-1];
					path[i][j] = k;
				}
			}
		}
	}
}
void output(int i, int j){
	if(i == j) return ;
	if(path[i][j] == 0) 
		printf("->(%d)->%s", f[i][j][P], Num[j].c_str());
	else{
		output(i,path[i][j]);
		output(path[i][j],j);
	}
}

int main(){
	freopen("data_71.in","r",stdin);
	scanf("%d", &P);
	for(int i = 1; i <= P; i++){ 
		string st; cin>>st;
		Addr[st] = i; Num[i] = st;
	}
	scanf("%d", &Q); 
	memset(g, -1, sizeof(g)); memset(path,0,sizeof(path));
	while(Q--){
		string st1, st2; cin >> st1 >> st2;
		int w; scanf("%d", &w);
		g[Addr[st1]][Addr[st2]]=g[Addr[st2]][Addr[st1]]=w;
	}
	Floyd();
	scanf("%d", &R);
	while(R--){
		string st1, st2; cin>>st1>>st2;
		int i = Addr[st1], j = Addr[st2];
		//cout << f[i][j][P] << endl;
		cout << Num[i];
		output(i,j);
		cout << endl;
	}	
	return 0;
}