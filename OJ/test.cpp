#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define N 1010

using namespace std;

int l[N], r[N], d[N], s[N], h[N];
int now[N], sum[N], del[N], alt[N];
int a[N];
int n, k;
int f[N][N],c[N][N];
int p, ans, tot;

int merge(int x, int y){
	if(!x) return y;
	if(!y) return x;
	if(d[x]<d[y]) swap(x,y);
	r[x] = merge(r[x],y);
	if(h[l[x]]<h[r[x]]) swap(x,y);
	h[x] = h[r[x]] + 1;
	return x;
}
inline int dat(int p){
	return (d[s[p]]*now[p]-sum[p]) + (alt[p]-d[s[p]]*del[p]);
}
int solve(){
	for(int i = 1; i <= n; i++){
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		p = tot = ans = 0;
		for(int j = i; j <= n; j++){
			d[++tot]=a[i]; s[++p]=tot;
			now[p] = 1; sum[p] = a[i];
			alt[p] = 0; del[p] = 0;
			while(p>1 && d[s[p-1]]>d[s[p]]){
				now[p-1]+=now[p]; sum[p-1]+=sum[p];
				alt[p-1]+=alt[p]; del[p-1]+=del[p];
				s[p-1] = merge(s[p-1],s[p]);
				p--;
				while(now[p]>del[p]+1){
					now[p]--; del[p]++;
					alt+=d[s[p]]; sum[p]-=d[s[p]];
					s[p] = merge(l[s[p]],r[s[p]]);
				}
				ans+=dat(p);
			}
			c[i][j]=min(c[i][j],ans);
		}
	}
}

int main(){
	while(sc)

}