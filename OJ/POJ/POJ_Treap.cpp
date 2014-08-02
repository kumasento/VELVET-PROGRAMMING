#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>

using namespace std;
int T;
struct node{
	node *ch[2];
	int r; string v;
	int cmp(string st){ return (st>v) ? 1 : 0; }
};
void rotate(node* &t, int d){
	node *k = t->ch[d^1];
	t->ch[d^1] = k->ch[d];
	k->ch[d] = t;
	t = k;
}
void insert(node *&t, int r, string st, node *sig){
	if(t==NULL || t==sig){
		t = new node();
		t->ch[0] = t->ch[1] = NULL;
		t->r=r; t->v=st;
		return ;
	}
	else{
		int d = t->cmp(st);
		insert(t->ch[d], r, st, sig);
		if( t->ch[d]->r > t->r )
			rotate( t, d^1 );
		return ;
	}
}
void print(node * t){
	if(t==NULL) return ;
	putchar('(');
	print(t->ch[0]);
	printf("%s/%d", t->v.c_str(), t->r);
	print(t->ch[1]);
	putchar(')');
}

int main(){
	freopen("data_treap.in","r",stdin);
	while(cin>>T){
		if(T==0) break;
		map<int,string> mm;
		for(int i = 0; i < T; i++){
			char v[100]; int r;
			scanf(" %[a-z]/%d", v, &r );
			mm[r]=string(v);
		}
		node *t = new node(), *sig = new node();
		t = sig;
		map<int,string>::iterator i = mm.begin();
		while( i != mm.end() ){
			insert(t, i->first, i->second, sig);
			i++;
		}
		print(t); cout << endl;
	}
	return 0;
}