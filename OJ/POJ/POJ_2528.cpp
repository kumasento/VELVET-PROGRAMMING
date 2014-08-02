#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>

#define MAXN 50010

using namespace std;
int N, a[MAXN*2], b[MAXN][2], len; 
struct node{
	int L, R;
	node *ch[2];
	int id; int vis;
}; 
set<int> ids;
int cmp(const void *a, const void *b){ return *(int*)a-*(int*)b;}
void build(int L, int R, node *t){
	if(t==NULL) return;
	if(a[L]==a[R]) return ; 
	int LL=a[L], RR=a[R];
	int mid=(L+R)>>1;
	t->ch[0]=new node(); t->ch[1]=new node();
	t->ch[0]->L=LL; t->ch[0]->R=a[mid]; 
	t->ch[1]->L=a[mid+1]; t->ch[1]->R=RR;
	build(L, mid, t->ch[0]);
	build(mid+1, R, t->ch[1]);
	return ;
}
void print(node *t){
	if(t==NULL) return ;
	printf("%d %d %d\n", t->L, t->R, t->id);
	print(t->ch[0]);
	print(t->ch[1]);
}
void change(int LL, int RR, int delta, node *t){
	if(t==NULL) return ;
	//printf("(%d %d) (%d %d)\n", LL, RR, t->L, t->R);
	if(t->L==LL && t->R==RR){ t->id=delta; t->vis=1; return ;}
	//int L = *lower_bound(a, a+len, t->L), R = *lower_bound(a , a+len, t->R);
	int L1=t->ch[0]->L, L2=t->ch[1]->L, R1=t->ch[0]->R, R2=t->ch[1]->R;
	if(t->vis){
		t->ch[0]->id=t->id; t->ch[0]->vis=1;
		t->ch[1]->id=t->id; t->ch[1]->vis=1;
		t->vis=0; t->id=0;
	}
	if(RR<=R1)
		change(LL,RR,delta,t->ch[0]);
	else if(LL>=L2)
		change(LL,RR,delta,t->ch[1]);
	else{
		change(LL,R1,delta,t->ch[0]);
		change(L2,RR,delta,t->ch[1]);
	}
	
	return;
}
void update(node *t){
	if(t==NULL) return;
	if(t->vis==1) { ids.insert(t->id); return; }
	update(t->ch[0]);
	update(t->ch[1]);
}

int main(){
	freopen("data_2528.in","r",stdin);
	int c; cin>>c;
	while(c--){
		cin>>N; int index = 1;
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
		for(int i=1; i<=N; i++, index+=2){
			scanf("%d%d", &a[index], &a[index+1]);
			b[i][0] = a[index]; b[i][1] = a[index+1];
		}
		len = index-1; qsort(a+1, len, sizeof(int), cmp); index=2;
		for(int i=2; i<=len; i++)
			if(a[i]!=a[i-1])
				a[index++]=a[i]; 
		len=index-1; qsort(a+1, len, sizeof(int), cmp);
		index = len+1;
		for(int i=2; i<=len; i++)
			if(a[i]>a[i-1]+1)
				a[index++]=a[i-1]+1;
		len=index-1; qsort(a+1, len, sizeof(int), cmp);
		//for(int i=1; i<=len; i++) cout<<a[i]<<' '; cout << endl;

		node *t = new node(); t->L=a[1]; t->R=a[len]; 
		build(1,len,t);

		//print(t);
		for(int i=1; i<=N; i++){
			change(b[i][0], b[i][1], i, t);
			//print(t); cout << endl;
		}
		
		ids.clear();
		update(t);
		cout<<ids.size()<<endl;
		
	}

	return 0;
}