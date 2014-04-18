#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>

#define MAXN 100010

using namespace std;

typedef long long ll;
ll N, Q, a[MAXN];
struct node{
	ll L, R;
	ll sum;
	ll delta;
	node *ch[2];
} *tree;

void build(node *t){
	if(t==NULL) return;
	if(t->L==t->R) { t->sum=a[t->L]; t->delta=0; return; }
	int mid=(t->L+t->R)>>1;
	t->ch[0]=new node(); t->ch[1]=new node();
	t->ch[0]->L=t->L; t->ch[0]->R=mid; t->ch[1]->L=mid+1; t->ch[1]->R=t->R;
	build(t->ch[0]); build(t->ch[1]);
	t->sum=t->ch[0]->sum+t->ch[1]->sum; t->delta=0;
}
ll query(ll L, ll R, node* t){
	//if(t==NULL) return 0;
	if(t->L>=L && t->R<=R){ return t->sum+t->delta*(R-L+1); }
	ll mid=(t->L+t->R)>>1;
	ll d = t->delta; t->sum+=d*(t->R-t->L+1); t->delta=0;
	t->ch[0]->delta+=d; t->ch[1]->delta+=d;
	if(mid<L)
		return query(L,R,t->ch[1]);
	else if(mid>=R)
		return query(L,R,t->ch[0]);
	else{
		ll q1=query(L,mid,t->ch[0]);
		ll q2=query(mid+1,R,t->ch[1]);
		return q1+q2;
	}
}
void print(node *t){
	if(t==NULL) return ;
	printf("%lld %lld %lld %lld\n", t->L, t->R, t->sum, t->delta);
	print(t->ch[0]);
	print(t->ch[1]);
}
void add(ll L, ll R, ll delta, node* t){
	//if(t==NULL) return ;
	//printf("(%lld,%lld) (%lld,%lld)\n", L,R,t->L,t->R);
	if(t->L>=L && t->R<=R) { t->delta+=delta; return ; }
	int mid=(t->L+t->R)>>1;

	ll d = t->delta; t->sum+=d*(t->R-t->L+1); t->delta=0;
	t->sum+=delta*(R-L+1);
	t->ch[0]->delta+=d; t->ch[1]->delta+=d;
	//print(tree); cout << endl;
	if(mid>=R)
		add(L,R,delta,t->ch[0]);
	else if(mid<L)
		add(L,R,delta,t->ch[1]);
	else{
		add(L,mid,delta,t->ch[0]);
		add(mid+1,R,delta,t->ch[1]);
	}
	return ;
}


int main(){
	freopen("data_3468.in","r",stdin);
	//freopen("data_3468.out","w",stdout);
	scanf("%lld%lld", &N, &Q);
	for(int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	node *t = new node(); t->L = 1; t->R = N; build(t);
	//print(t); cout << endl;
	tree=t;
	while(Q--){
		string q; cin >> q; 
		if(q[0]=='Q'){
			ll a, b; scanf("%lld%lld", &a, &b);
			printf("%lld\n",query(a, b, t));
		}
		else{
			ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
			add(a, b, c, t);
			//cout << "---" << endl;
		}
//		print(t); cout << endl;

	}

	return 0;
}