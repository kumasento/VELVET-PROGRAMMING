#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

#define MAXN 100

using namespace std;

struct edge{
	int u, v;
	int w;
} e[MAXN];

int cmp(const void *a, const void *b){ return ((edge*)a)->w - ((edge*)b)->w; }

int f[MAXN];
int Find(int x){
	if(f[x] == x) return x;
	return Find(f[x]);
}
void Union(int x, int y){
	int rx = Find(x);
	int ry = Find(y);
	if(rx == ry) return;
	f[ry] = rx;
	return;
}

int main(){
	freopen("data_72_2.in", "r", stdin);
	int n; 
	while(scanf("%d",&n)==1 && n){
		memset(e, 0, sizeof(e));
		int index = 0;
		for(int i = 0; i < n-1; i++){
			char ch[2]; int x;
			scanf("%s%d", ch, &x);
			for(int j = 0; j < x; j++){
				char cc[2]; int w; 
				scanf("%s%d", cc, &w);
				int p1 = ch[0]-'A'+1, p2 = cc[0]-'A'+1;
				e[index].u = p1, e[index].v = p2, e[index].w = w; index++;
				e[index].u = p2, e[index].v = p1, e[index].w = w; index++;
			}	
		}
		qsort(e, index, sizeof(e[0]), cmp);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			f[i] = i;
		int t = 0, len = index;
		index = 0;
		int cnt = 0;
		while( t < n-1 ){
			int x = e[index].u, y = e[index].v;
			if(Find(x) == Find(y))
				index++;
			else{
				Union(x, y);
				t++;
				cnt += e[index].w;
				index++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}