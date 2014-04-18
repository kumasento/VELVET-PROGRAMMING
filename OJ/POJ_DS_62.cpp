#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 50010

using namespace std;

int m, n;
int a[MAXN];

int Find(int i){
	while(a[i] > 0)
		i = a[i];
	return i;
}	
void Union(int A, int B){
	int ra = Find(A), rb = Find(B);
	if(ra == rb) return;
	int ha = a[ra], hb = a[rb];
	if(ha < hb){
		a[rb] = ra;
		a[ra] += hb;
	}
	else{
		a[ra] = rb;
		a[rb] += ha;
	}
	return ;
}

int main(){
	freopen("data_62.in","r",stdin);
	int T = 1;
	while(scanf("%d%d",&n,&m) == 2){
		if(n == 0 && m == 0) break;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i ++)
			a[i] = -1;
		int i, j; 
		while(m --){
			scanf("%d%d", &i, &j);
			Union(i, j);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] < 0)
				cnt ++;
		printf("Case %d: %d\n", T, cnt);
		T++;
	}
	return 0;
}