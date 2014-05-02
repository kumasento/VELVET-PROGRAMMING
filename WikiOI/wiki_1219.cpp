#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 110

using namespace std;

int main(){
	freopen("1219.in", "r", stdin);
	int n, m; cin>>n>>m;
	int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
	long long dp[MAXN][MAXN]; memset(dp, 0, sizeof(dp));
	dp[x1][y1] = 1;
	for(int i = x1+1; i <= x2; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i-2][j-1]+dp[i-2][j+1]+dp[i-1][j-2]+dp[i-1][j+2];
		}
	}
	cout << dp[x2][y2] << endl;
	return 0;
}