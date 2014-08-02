#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

#define NN 20010

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

int main(){
    freopen("data_3261.in","r",stdin);
    scanf("%d%d", &N, &K);
    int a[N]; memset(a, 0, sizeof(a));
    for(int i = 0; i < N; i++)
        cin>>a[i];

    sa<int,NN> SA;
    SA.init(a, N);
    SA.calc();
    int i, j, k, tot, maxx = 0;
    int low, high, mid; 
    low=1, high=N;
    while(low<=high){
        mid = low+(high-low)/2;
        for(tot=1, i=1; i<=N; i++){
            if(SA.height[i]>=mid) tot++;
            else tot = 1;
            if(tot>=K) break;
        }
        if(tot>=K) low=mid+1, maxx=mid;
        else high=mid-1;
    }
    cout << maxx << endl;
    return 0;
}