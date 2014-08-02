#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stack>

#define N 2005

using namespace std;

struct node{
	int k, d;
	node *l, *r;
};
node *head[N];
int l[N], r[N];
int a[N];

void Left_tree_Merge(node *t1, node *t2){
	node *t=t1->r; t1->r=t2;
	if(t==NULL) return ;
	node *w=t1;
	while(w->r!=NULL && w->r->k > t->k)
		w=w->r;
	if(w->r==NULL)
		w->r=t;
	else{
		node *tmp = w->r;
		w->r = t;
		Left_tree_Merge(t,tmp);
	}
}
node * Left_tree_pop(node *t){
	if(t->l==NULL && t->r!=NULL)
		return t->r;
	if(t->l!=NULL && t->r==NULL)
		return t->l;
	if(t->l->k<t->r->k){
		swap(t->l,t->r);
	}
	Left_tree_Merge(t->l, t->r);
	return t->l;
}
int update(node * t){
	if(t==NULL) return -1;
	int l1=update(t->l);
	int l2=update(t->r);
	t->d=min(l1,l2)+1;
	if(l1<l2)
		swap(t->l,t->r);
	return t->d;
}
int solve(int n){
	int I = 0;
	for(int i = 0; i < n; i++, I++){
		head[I]=new node();
		head[I]->d=0;
		head[I]->l=head[I]->r=NULL;
		head[I]->k=a[i];
		l[I]=r[I]=i;
		while(I>0 && head[I-1]->k>=head[I]->k){
			Left_tree_Merge(head[I-1],head[I]);
			update(head[I-1]);
			if((r[I]-l[I]+1)%2==1 && (r[I-1]-l[I-1]+1)%2==1){
				head[I-1]=Left_tree_pop(head[I-1]);
				update(head[I-1]);
			} 
			r[I-1]=r[I];
			I--;
		}
	}
	int ans=0;
	for(int i=0; i<I; i++){
		for(int j=l[i]; j<=r[i]; j++)
			ans+=(abs(head[i]->k-a[j]));
	}
	return ans;
}

int main(){
	freopen("data_3666.in","r",stdin);
	int n;
    while(scanf("%d",&n)!=EOF){
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