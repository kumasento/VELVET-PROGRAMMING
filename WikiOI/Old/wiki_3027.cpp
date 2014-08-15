#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 1010

using namespace std;

struct p{
	int l, r;
	int v;
} ps[MAXN];

int cmp(const void *a, const void *b){
	p * p1 = (p*)a, *p2 = (p*)b;
	if(p1->r == p2->r)
		return p1->l - p2->l;
	else
		return p1->r - p2->r;
}

int main(){
	freopen("3027.in", "r", stdin);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d%d%d", &ps[i].l, &ps[i].r, &ps[i].v);

	qsort(ps, n, sizeof(ps[0]), cmp);

	int dp[n]; memset(dp, 0, sizeof(dp));
	for(int i = n-1; i >= 0; i--){
		int max = 0;
		for(int j = i+1; j < n; j++){
			if(ps[j].l >= ps[i].r && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + ps[i].v;
	}

	int tmp_max = 0;
	for(int i = 0; i < n; i++)
		if(tmp_max < dp[i])
			tmp_max = dp[i];

	cout << tmp_max << endl;

	return 0;
}