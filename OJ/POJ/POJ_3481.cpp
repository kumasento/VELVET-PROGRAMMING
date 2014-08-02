#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

struct node{
	int v, r;
	friend bool operator<(node a, node b){
		return a.r<b.r;
	}
};
set<node> st;

int main(){
	freopen("data_3481.in","r", stdin);
	int T; cin>>T;
	while(T!=0){
		if(T==1){
			int v, r; scanf("%d%d", &v, &r);
			node t; 
			t.v=v; t.r=r;
			st.insert(t);
		} else if(T==2){
			if(st.empty()) printf("0\n");
			else{
				set<node>::iterator i = st.end(); i--;
				printf("%d\n", i->v);
				st.erase(i);
			}
		} else if(T==3){
			if(st.empty()) printf("0\n");
			else{
				set<node>::iterator i = st.begin();
				printf("%d\n", i->v);
				st.erase(i);
			}
		}

		cin>>T;
	}

	return 0;
}