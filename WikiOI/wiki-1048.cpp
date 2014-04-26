#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("1048.in", "r", stdin);
	int n; cin>>n;
	int w[n]; memset(w, 0, sizeof(w));
	for(int i = 0; i < n; i++)
		cin>>w[i];

	int dp[n][n]; memset(dp, 0, sizeof(dp));
	int sum[n][n]; memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++){
		sum[i][i] = w[i];
		for(int j = i+1; j < n; j++)
			sum[i][j] = sum[i][j-1] + w[j];
	}

	for(int k = 2; k <= n; k++){
		// width
		for(int i = 0; i < n-k+1; i++){
			// start
			int min = 0x7fffffff;
			for(int j = i; j < i+k-1; j++){
				//mid
				/*
				 *	The cost should be: 
				 * 	"merge cost + inner merge cost(pile weight)"
				 */
				if(dp[i][j] + dp[j+1][i+k-1] + sum[i][i+k-1] < min)
					min = dp[i][j] + dp[j+1][i+k-1] + sum[i][i+k-1];
			}
			dp[i][i+k-1] = min;
		}
	}

	cout << dp[0][n-1] << endl;
	return 0;
}