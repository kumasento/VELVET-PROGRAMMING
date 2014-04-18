#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define MAXN 50010
#define INF 1000010

using namespace std;

int N, Q;
long long a[MAXN];
struct node{
	node *ch[2];
	long long nMax, nMin;
	int L, R;
};
struct MinMax{
	int Min,Max;
};
void build(node* p){
	if(p == NULL) return ;
	if(p->L == p->R){ p->nMax = p->nMin = a[p->L]; }
	else{
		int mid=(p->L+p->R)>>1;
		p->ch[0] = new node();
		p->ch[0]->L = p->L; p->ch[0]->R = mid;
		p->ch[1] = new node();
		p->ch[1]->L = mid+1; p->ch[1]->R = p->R;
		build(p->ch[0]); build(p->ch[1]);
		p->nMin=(p->ch[0]->nMin<p->ch[1]->nMin) ? p->ch[0]->nMin 
				: p->ch[1]->nMin;
		p->nMax=(p->ch[0]->nMax>p->ch[1]->nMax) ? p->ch[0]->nMax 
				: p->ch[1]->nMax;
	}
	return ;
}
MinMax Query(int L, int R, node* t){
	MinMax ans; ans.Min=INF; ans.Max=0;
	if(t==NULL) return ans;
	ans.Min=t->nMin; ans.Max=t->nMax;
	if(t->L==L && t->R==R) return ans;

	int mid = (t->L+t->R)>>1;
	MinMax r1, r2;
	if(mid>=R)
		return Query(L,R,t->ch[0]);
	else if(mid<L)
		return Query(L,R,t->ch[1]);
	else{
		r1=Query(L,mid,t->ch[0]);
		r2=Query(mid+1,R,t->ch[1]);
		ans.Min=min(r1.Min,r2.Min);
		ans.Max=max(r1.Max,r2.Max);
		return ans;
	}
}

void print(node *t){
	if(t==NULL) return ;
	cout << t->L << ' ' <<t->R<<' ' <<t->nMax<<' '<<t->nMin<<endl;
	print(t->ch[0]);
	print(t->ch[1]);
}

int main(){
	freopen("data_3264.in","r",stdin);
	int N, Q; scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++)	scanf("%lld", &a[i]);
	node *t = new node();
	t->L=1; t->R=N; build(t);
	//print(t);
	for(int i = 0; i < Q; i++){
		int A, B; scanf("%d%d", &A, &B);
		MinMax ans = Query(A,B,t);
		printf("%d\n", ans.Max-ans.Min);
	}
	return 0;
}