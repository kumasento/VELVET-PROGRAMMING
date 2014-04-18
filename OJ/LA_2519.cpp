#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>

#define MAXN 1010

using namespace std;

struct intr{
	double l, r;
} S[MAXN];

int cmp(const void*a, const void *b){
	intr *s1 = (intr*)a, *s2 = (intr*)b;
	if(s1->r == s2->r) return ((s1->l-s2->l)<0)?-1:1;
	else return ((s1->r-s2->r)<0)?-1:1;
}

int main(){
	freopen("data_la2519.in","r",stdin);
	int n, d, T = 0;
	while(scanf("%d%d", &n, &d) == 2 && !(n==0 && d==0)){
		printf("Case %d: ", ++T);
		memset(S, 0, sizeof(S));
		int ok = 1;
		for(int i = 0; i < n; i++){
			int X, Y; scanf("%d%d", &X, &Y);
			if(d < Y) { ok = 0; }
			else{ 
				double delta = sqrt(d*d-Y*Y);
				S[i].l = ((double)X)-delta; S[i].r = ((double)X)+delta;
			}
		}
		if(ok){ 
			qsort(S, n, sizeof(S[0]), cmp);
			
			int cnt = 0;
			int vis[n]; memset(vis, 0, sizeof(vis));
			for(int i = 0; i < n; i++){
				if(!vis[i]){
					vis[i] = 1; cnt++;
					for(int j = i+1; j < n; j++)
						if(!vis[j] && S[i].r>=S[j].l && S[i].r<=S[j].r)
							vis[j] = 1;
				}
			}
			cout << cnt << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}