#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

struct node {
	node *ch, *sb;
	int v, k;
};

void Insert(node *&o, string st, int i){
	int n = st[i]-'0';
	if(o->ch == NULL){
		// build a new child
		o->ch = new node();
		(o->ch)->ch = (o->ch)->sb = NULL;

		(o->ch)->v = n; (o->ch)->k = 1;
		if(i == st.length()-1)
			return;
		Insert(o->ch, st, i+1); return ;
	}

	node *w = o->ch;
	while(w != NULL){
		if(w->v == n)
			break;
		if(w->sb == NULL)
			break;
		w = w->sb;
	}
	if(w->sb == NULL && w->v != n){
		(w)->sb = new node();
		((w)->sb)->ch = ((w)->sb)->sb = NULL;
		((w)->sb)->v = n; ((w)->sb)->k = 1;
		if(i == st.length()-1)
			return;
		Insert((w)->sb, st, i+1); return ;
	}

	w->k ++;
	if(i == st.length()-1)
		return;
	Insert(w, st, i+1); 
	return ;
}

void Print(node *o){
	if( o == NULL) return ;
	cout << o->v <<' ' << o->k<<endl;;
	node *t = o->ch;
	while(t != NULL){
		Print(t);
		t = t->sb;
	}
	//cout << endl;
	return;
}

int Check(node *o){
	if(o==NULL) return 1;
	node * w = o->ch; int cnt = 0;
	while(w != NULL){ 
		//cout << w->v << ' ' << w->k << endl;
		cnt += w->k; 
		w = w->sb;
	}
	//cout << o->v << ' ' << o->k << ' ' << cnt << endl;
	if(cnt < o->k && cnt)
		return 0;
	else{
		w = o->ch; int ok = 1;
		while(w != NULL && ok){
			ok = Check(w);
			w = w->sb;
		} 
		return ok;
	}
}

int main(){
	freopen("data_61.in","r",stdin);
	int t; scanf("%d", &t);
	while(t --){
		int n; scanf("%d", &n);

		node * t = new node();
		t->ch = t->sb = NULL;

		while(n--){
			string st; cin >> st;
			Insert(t, st, 0);
		}	
		//Print(t);
		//cout << endl;
		node *w = t->ch;
		int ok = 1;
		while( w != NULL && ok ){
			ok = Check(w);
			//cout << w->v << ' ' << ok << endl;
			w = w->sb;
		}
		if(!ok) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}