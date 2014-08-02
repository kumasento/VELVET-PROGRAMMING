#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

#define MAXN 50010

using namespace std;

int a[MAXN];
int r[MAXN];

int Find(int x){
	if(a[x] == x) return x;
	int tx = a[x];
	a[x] = Find(a[x]);
	r[x] = (r[x]+r[tx])%3;
	return a[x];
}
void Union(int x, int y, int d){
	int ra = Find(x), rb = Find(y);
	a[rb] = ra;
	r[rb] = (r[x]-r[y]+3+(d-1))%3;
}


int main(){
	freopen("data_65.in", "r", stdin);
	int N, K; scanf("%d%d", &N, &K);
	memset(a, 0, sizeof(a));
	memset(r, 0, sizeof(r));
	for(int i = 1; i <= N; i++)
		a[i] = i;

	int cnt = 0;
	while(K--){
		int d, x, y; scanf("%d%d%d", &d, &x, &y);
		if(x > N || y > N || (d==2 && x==y)) 
			cnt++;
		else if(Find(x) == Find(y)){
			if(d == 1 && r[x] != r[y]) cnt++;
			if(d == 2 && (r[x]+1)%3 != r[y]) cnt++;
		}
		else Union(x,y,d);
	}
	printf("%d\n", cnt);
	return 0;
}