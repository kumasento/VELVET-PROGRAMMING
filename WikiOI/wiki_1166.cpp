#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("1166.in", "r", stdin);
	int n, m; cin>>n>>m;
	int M[n][m]; memset(M, 0, sizeof(M));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>M[i][j];

	// This version doesnt have the high precise arithmetic part
	int ans = 0;
	for(int w = 0; w < n; w++){
		int dp[m][m]; memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++)
			dp[i][i] = M[w][i] * (2<<(m-1));
		for(int k = 2; k <= m; k++){
			for(int i = 0; i <= m-k; i++){
				int r1 = dp[i+1][i+k-1] + M[w][i]*(2<<(m-k));
				int r2 = dp[i][i+k-2] + M[w][i+k-1]*(2<<(m-k));
				dp[i][i+k-1] = max(r1, r2); 
			}
		}
		ans += dp[0][m-1];
	}

	cout << ans << endl;
	return 0;
}