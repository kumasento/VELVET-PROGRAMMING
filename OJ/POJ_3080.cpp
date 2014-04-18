#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

#define NN 1000

template <class T,int size>
class sa{
public:
    T a[size+1];
    int i,j,k,sa[size+1],rank[size+1],height[size+1],l,n,p[size+1],mid,tmp;
    void init(T *a_,int n_)
    {
        memmove(a,a_,sizeof(a));
        n=n_;
        a[n]=0;
    }
    void sort(int l,int r)  //对字符串进行排序，这里用的是快速排序，最好用基数排序
    {
        int i,j;
        i=l;j=r;
        mid=sa[(l+r)>>1];
        while (i<=j)
        {
            while (p[sa[i]]<p[mid]) i++;
            while (p[sa[j]]>p[mid]) j--;
            if (i<=j)
            {
                tmp=sa[i];sa[i]=sa[j];sa[j]=tmp;
                i++;j--;
            }
        }
        if (i<r) sort(i,r);
        if (l<j) sort(l,j);
    }
    void calc1(int i,int j)  //计算rank信息
    {
        sort(i,j-1);
        rank[sa[i]]=i;
        for (i++;i<j;i++)
        if (p[sa[i]]==p[sa[i-1]]) rank[sa[i]]=rank[sa[i-1]];
        else rank[sa[i]]=i;
    }
    void calc()
    {
        for (i=0;i<n;i++)
        {
            sa[i]=i;
            p[i]=a[i];
        } //初始化
        calc1(0,n);//第一次排序
        l=1;//l为倍增长度
        while (l<n)
        {
            for (i=0;i+l<n;i++) p[i]=rank[i+l];  //更新pl
            for (i;i<n;i++) p[i]=-1;
            for (i=0;i<n;i=j)//根据l进行排序
            {
                j=i;
                while (j<n&&rank[sa[i]]==rank[sa[j]]) j++;
                calc1(i,j);
            }
            l+=l  ; //倍增l
        }
        //求height数组
        for (i=0;i<n;i++)
            if (j=rank[i])
            {
                if (i) l=height[rank[i-1]]-1;
                else l=0;
                if (l<0) l=0;  //l为下界
                while (a[i+l]==a[sa[j-1]+l]) l++;
                height[j]=l;  //更新height数组
            } else 
            height[0]=0; 
    }
};

int N, K; 
int loc[NN], m;
char str[NN], res[NN];
int num[NN];
bool vis[1004];

bool check(int mid, int len, sa<int,NN> SA){
    int i, j, tot;
    tot = 0;
    memset(vis, 0, sizeof(vis));
    for(i=2; i<=len; i++){
        if(SA.height[i]<mid){
            memset(vis,0,sizeof(vis));
            tot=0;
        }
        else{
            if(!vis[loc[SA.sa[i-1]]]){
                vis[loc[SA.sa[i-1]]]=1;
                tot++;
            }
            if(!vis[loc[SA.sa[i]]]){
                vis[loc[SA.sa[i]]]=1;
                tot++;
            }
            //cout << tot << endl;
            if(tot==m){
                //cout << tot << endl;
                for(j=0; j<mid; j++)
                    res[j]=num[SA.sa[i]+j]+'A'-1;
                res[mid]='\0';
            }
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("data_3080","r",stdin);
    int n, k, i, j, a, b, sp, ans, cas;
    scanf("%d", &cas);
    while(scanf("%d", &m)!=EOF){
        sp = 29; n = 0; ans = 0;
        for(i = 1; i <= m; i++){
            scanf("%s", str);
            for(j=0; str[j]; j++){
                loc[n]=i;
                num[n++]=str[j]-'A'+1;
            }
            loc[n] = sp;
            num[n++] = sp++;
        }
        num[n]=0;
        sa<int,NN> SA; SA.init(num,n+1); SA.calc();
        int left=0, right=strlen(str), mid;
        while(right>=left){
            mid=(right+left)/2;
            if(check(mid,n,SA)){
                left=mid+1;
                ans=mid;
            }
            else
                right=mid-1;
        } 
        if(ans>=3)
            printf("%s\n", res);
        else
            printf("no significant commonalities\n");
    }
    return 0;
}