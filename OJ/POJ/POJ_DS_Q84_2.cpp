#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N = 100+10;
const int M = 10000+10;
struct Point
{
    double x,y;
}p[N];
struct edge
{
    int u,v;
    double cost;
    edge(){}
    edge(int u,int v,double c):u(u),v(v),cost(c){}
}e[M];
int pre[N],hash1[N],vis[N];
double In[N];
inline double dist(Point& a,Point& b)
{
    return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
double Directed_MST(int root,int n,int m)
{
    double ret=0;
    while(true)
    {
        for(int i=0;i<n;i++)
            In[i]=INT_MAX;
        for(int i=0;i<m;i++)//找最小入边
        {
            int u=e[i].u;
            int v=e[i].v;
            if(e[i].cost<In[v] && u!=v){
                pre[v]=u;
                In[v]=e[i].cost;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==root)
                continue;
            if(In[i]==INT_MAX)
                return -1;
        }
        int cntnode=0;
        memset(hash1,-1,sizeof(hash1));
        memset(vis,-1,sizeof(vis));
        In[root]=0;
        for(int i=0;i<n;i++)//找环
        {
            ret+=In[i];
            int v=i;
            while(vis[v]!=i && hash1[v]==-1 && v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root && hash1[v]==-1)
            {
                for(int u=pre[v];u!=v;u=pre[u])
                    hash1[u]=cntnode;
                hash1[v]=cntnode++;
            }
        }
        if(cntnode==0)
            break;
        for(int i=0;i<n;i++)
            if(hash1[i]==-1)
                hash1[i]=cntnode++;
        for(int i=0;i<m;i++)//重标记
        {
            int v=e[i].v;
            e[i].u=hash1[e[i].u];
            e[i].v=hash1[e[i].v];
            if(e[i].u!=e[i].v)
                e[i].cost-=In[v];
        }
        n=cntnode;
        root=hash1[root];
    }
    return ret;
}
int main()
{
    freopen("data_Q84.in", "r", stdin); 
    int a,b;
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        int mm=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(a==b)continue;
            a--,b--;
            e[mm++]=edge(a,b,dist(p[a],p[b]));
            //printf("%lf\n",e[mm-1].cost);
        }
        double ans=Directed_MST(0,n,mm);
        if(ans==-1)
            puts("NO");
        else printf("%.2f\n",ans);
    }
    return 0;
}