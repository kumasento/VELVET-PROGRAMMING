#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int u=1010;
int a[u],c[u][u],f[u][u],s[u],d[u],l[u],r[u],h[u],now[u],sum[u],del[u],alt[u];
int n,m,i,j,k,tot,p,ans;
int merge(int x,int y)
{
 if(!x) return y;
 if(!y) return x;
 if(d[x]<d[y]) swap(x,y);
 r[x]=merge(r[x],y);
 if(h[l[x]]<h[r[x]]) swap(l[x],r[x]);
 h[x]=h[r[x]]+1;
 return x;
}
inline int dat(int p)
{
 return d[s[p]]*now[p]-sum[p]+alt[p]-d[s[p]]*del[p];
}
void solve()
{
 for(i=1;i<=n;i++)
 {
  memset(l,0,sizeof(l));
  memset(r,0,sizeof(r));
  tot=p=ans=0;
  for(j=i;j<=n;j++)
  {
   d[++tot]=a[j],s[++p]=tot;
   now[p]=1,sum[p]=a[j],del[p]=alt[p]=0;
   while(p>1&&d[s[p]]<d[s[p-1]])
   {
    ans-=dat(p)+dat(p-1);
    sum[p-1]+=sum[p],now[p-1]+=now[p],alt[p-1]+=alt[p],del[p-1]+=del[p];
    s[p-1]=merge(s[p-1],s[p]);
    p--;
    while(now[p]>del[p]+1)
    {
     now[p]--,del[p]++,sum[p]-=d[s[p]],alt[p]+=d[s[p]];
     s[p]=merge(l[s[p]],r[s[p]]);
    }
    ans+=dat(p);
   }
   c[i][j]=min(c[i][j],ans);
  }
 }
}
int main()
{
  freopen("data_3016.in","r",stdin);1
 while(cin>>n>>m&&n)
 {
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  memset(f,0x3f,sizeof(f));
  memset(c,0x3f,sizeof(c));
  for(i=1;i<=n;i++) a[i]-=i;
  solve();
  for(i=1;i<=n;i++) a[i]=-(a[i]+i+i);
  solve();
  f[0][0]=0;
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    for(k=0;k<i;k++)
     f[i][j]=min(f[i][j],f[k][j-1]+c[k+1][i]);
  cout<<f[n][m]<<endl;
 }
 return 0;
}
