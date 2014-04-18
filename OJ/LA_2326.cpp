#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define MAXN 205

using namespace std;

struct intr{
	int l, r;
} S[MAXN];

int cmp(const void *a, const void *b){
	intr* s1 = (intr*)a, *s2 = (intr*)b;
	if(s1->l != s2->l) return s1->l-s2->l;
	else  return s1->r-s2->r;
}

int main(){
	freopen("data_LA2322.in", "r", stdin);
	int T; cin>>T;
	while(T--){
		int n; cin>>n;
		memset(S, 0, sizeof(S));
		for(int i = 0; i < n; i++)
			scanf("%d%d", &S[i].l, &S[i].r);
		for(int i = 0; i < n; i++){
			if(S[i].l > S[i].r) 
				swap(S[i].l, S[i].r);
			S[i].l = (S[i].l+1)/2;
			S[i].r = (S[i].r+1)/2;
		}
		qsort(S, n, sizeof(S[0]), cmp);

		int vis[n]; memset(vis, 0, sizeof(vis));
		int cnt = 0;
		while(1){
			int i;
			for(i = 0; i < n; i++)
				if(!vis[i]) break;
			if(i == n) break;
			vis[i] = 1;
			cnt ++;
			int r = S[i].r;
			for(int j = i+1; j < n; j++){
				if(!vis[j] && S[j].l > r){
					vis[j] = 1;
					r = S[j].r;
				}
			}
		}
		cout << cnt * 10 << endl;
	}
	return 0;
}