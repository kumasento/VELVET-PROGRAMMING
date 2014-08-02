#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>

#define N 1010

using namespace std;

int l[N], r[N], s[N], d[N], h[N];
int a[N];
int n, k;
int now[N], sum[N], del[N], alt[N];
int f[N][N], c[N][N];
int tot, p, ans;

int merge(int x, int y){
	if(!x) return y;
	if(!y) return x;
	if(d[x]<d[y]) swap(x,y);
	r[x]=merge(r[x],y);
	if(h[l[x]]<h[r[x]]) swap(l[x],r[x]);
	h[x]=h[r[x]]+1;
	return x;
}

inline int dat(int I){
	return (d[s[I]]*now[I]-sum[I])+(alt[I]-d[s[I]]*del[I]);
}
void solve(){
	for(int j = 1; j <= n; j++){
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		tot=p=ans=0;
		for(int i = j; i <= n; i++){
			d[++tot]=a[i]; s[++p]=tot;
			now[p]=1; sum[p]=a[i]; del[p]=0; alt[p]=0;
			while(p>1 && d[s[p]]<d[s[p-1]]){
				ans-=dat(p)+dat(p-1);
				sum[p-1]+=sum[p]; now[p-1]+=now[p]; 
				alt[p-1]+=alt[p]; del[p-1]+=del[p];
				s[p-1]=merge(s[p-1],s[p]);
				p--;
				while(now[p]>del[p]+1){
					now[p]--; del[p]++; sum[p]-=d[s[p]];  alt[p]+=d[s[p]];
					s[p]=merge(l[s[p]],r[s[p]]);
				}
				ans+=dat(p);
			}
			c[j][i] = min(c[j][i], ans);
		}
	}
}
int main(){
	freopen("data_3016.in","r",stdin);
	while(scanf("%d%d", &n, &k) && n){
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(f, 0x3f, sizeof(f));
		memset(c, 0x3f, sizeof(c));
		for(int i = 1; i <= n; i++) a[i]-=i;
		solve();
		for(int i = 1; i <= n; i++) a[i]=-(a[i]+2*i);
		solve();
		f[0][0] = 0;
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= k; j++)
				for(int t = 0; t < i; t++)
					f[i][j] = min(f[i][j], f[t][j-1]+c[t+1][i]);
		printf("%d\n",f[n][k]);
	}

	return 0;
}