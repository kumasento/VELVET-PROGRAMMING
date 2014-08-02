#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAXN 5000
#define MAXM 15000

using namespace std;

int W[MAXN], D[MAXN];
int dp[MAXM];

int main(){
	freopen("3624.in", "r", stdin);
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d%d", &W[i], &D[i]);

	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		for(int v = M; v >= W[i]; v--)
			dp[v] = ((dp[v-W[i]]+D[i])>dp[v]) ? (dp[v-W[i]]+D[i]) : dp[v];
	}

	cout << dp[M] << endl;

	return 0;
}