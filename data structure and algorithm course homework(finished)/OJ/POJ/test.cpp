#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define LL long long
 
using namespace std;
 
const int N=2005;
struct node
{
    int k,d;
    struct node *l,*r;
};
struct node *head[N];//每个左偏树的根节点  大顶堆
int I;
int l[N],r[N];//每个左偏树的左右范围 不过我们这里只是保存了中位数(如果有n个元素 中位数我们这里定义为第 n/2个数) 和小于中位数的数
int a[N];
void  Left_tree_Merge(struct node *t1,struct node *t2)//将 t2指向的树合并到 t1
{
    struct node *t=t1->r;
    t1->r=t2;
    if(t==NULL)
    return;
    struct node *w=t1;
    while(w->r!=NULL&&w->r->k>t->k)//找到需要插入的地方 为 w的右孩子
    w=w->r;
    if(w->r==NULL)
    {w->r=t;}//为空直接插入
    else//否则递归合并
    {
        struct node *temp=w->r;
        w->r=t;
        Left_tree_Merge(t,temp);
    }
    return ;
}
struct node * Left_tree_pop(struct node *t)//弹出堆顶元素 
{
    if(t->l==NULL&&t->r!=NULL)
    {return t->r;}
    if(t->l!=NULL&&t->r==NULL)
    {return t->l;}
    if(t->l->k<t->r->k)
    swap(t->l,t->r);
    Left_tree_Merge(t->l,t->r);
    return t->l;
}
int update(struct node *t)//更新节点的 距离 维护左偏性
{
   if(t==NULL)
   return -1;
   int l1=update(t->l);
   int l2=update(t->r);
   t->d=min(l1,l2)+1;
   if(l1<l2)
   swap(t->l,t->r);
   return t->d;
}
int solve(int n)
{
    int I=0;
    for(int i=0;i<n;++i,++I)
    {
        head[I]=new node;
        head[I]->d=0;
        head[I]->l=head[I]->r=NULL;
        head[I]->k=a[i];
        l[I]=r[I]=i;
        while(I>0&&head[I-1]->k>=head[I]->k)//如果需要合并
        {
            Left_tree_Merge(head[I-1],head[I]);
            update(head[I-1]);//合并后更新
            /*
			if((r[I]-l[I]+1)%2==1&&(r[I-1]-l[I-1]+1)%2==1)//如果合并后元素过多 减少出一个 然后更新
            {
                head[I-1]=Left_tree_pop(head[I-1]);
                update(head[I-1]);
            }
			*/
            
			r[I-1]=r[I];//合并区间
            --I;
        }
    }

    int ans=0;
	cout << "======" << endl;
    for(int i=0;i<I;++i)
    {
		cout << head[i]->k << endl;

        for(int j=l[i];j<=r[i];++j)
        {
			cout << j << ' ' <<  abs(head[i]->k-a[j]) << endl;
            ans+=(abs(head[i]->k-a[j]));//累加
		}


    }
	cout << "------"<<endl;

    return ans;
}
int main()
{
    freopen("data.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        scanf("%d",&a[i]);//先求非递减的解
        int ans=solve(n);
        for(int i=0;i<n/2;++i)
        {
            swap(a[i],a[n-i-1]);//将数组逆序后 再求一边便是 非递加的了
        }
        ans=min(ans,solve(n));
        printf("%d\n",ans);
    }
    return 0;
}