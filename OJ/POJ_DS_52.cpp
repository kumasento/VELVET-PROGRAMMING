#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

#define MAXN 200

using namespace std;

struct node{
	int v;
	node *ch[2];
};

struct cmp{
	bool operator()(node* a, node* b){
		return a->v>b->v;
	}
};

priority_queue<node*, vector<node*>, cmp> Q;

int ans; 
void Print(node *t, int layer){

	if(t->ch[0] == NULL && t->ch[1] == NULL) { ans+=layer*t->v; return ; }
	else{
		Print(t->ch[0], layer+1);
		Print(t->ch[1], layer+1);
	}
}

int main(){
	freopen("data_52.in","r",stdin);
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++){ 
			node *t = new node();
			t->ch[0] = t->ch[1] = NULL;
			scanf("%d", &(t->v)); 
			Q.push(t);
		}
		node *p = NULL;
		while(!Q.empty()){
			p = Q.top(); Q.pop();
			if(Q.empty()) break;
			node *q = Q.top(); Q.pop();
			node *t = new node();
			t->v = p->v+q->v;
			t->ch[0] = p; t->ch[1] = q;
			Q.push(t);
		}
		ans = 0;
		Print(p, 0);
		cout << ans << endl;
	}

	return 0;
}