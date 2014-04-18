#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>

#define MAXN 5005

using namespace std;

struct stick{
	int len, wgt;
} S[MAXN];

int cmp(const void *a, const void *b){
	stick *s1 = (stick*)a, *s2 = (stick*)b;
	if(s1->wgt == s2->wgt) 
		return s1->len-s2->len;
	else 
		return s1->wgt-s2->wgt;
}

int main(){
	freopen("data_2322.in", "r", stdin);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		memset(S, 0, sizeof(S));

		for(int i = 0; i < n; i++)
			scanf("%d%d", &S[i].len, &S[i].wgt);
		qsort(S, n, sizeof(stick), cmp);

		int vis[n]; memset(vis, 0, sizeof(vis));
		int cnt = 0;
		while(1){
			int i;
			for( i = 0; i < n; i++)
				if(!vis[i]) break;
			if(i == n) break;
			vis[i] = 1;
			int l = S[i].len, w = S[i].wgt;
			for( int j = i+1; j < n; j++){
				if(!vis[j] && l <= S[j].len && w <= S[j].wgt )
					vis[j] = 1, l = S[j].len, w = S[j].wgt;
			}
			cnt ++;
		}
		cout << cnt << endl;
	}

	return 0;
}