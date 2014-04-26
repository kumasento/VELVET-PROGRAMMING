#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
	freopen("1154.in", "r", stdin);
	int n; cin>>n;
	int q[2*n]; memset(q, 0, sizeof(q));
	for(int i = 0; i < n; i++)
		cin>>q[i];
	for(int i = n; i < 2 * n; i++)
		q[i] = q[i-n];
	int dp[2 * n][2 * n]; memset(dp, 0, sizeof(dp));

	// init
	for(int i = 0; i < 2*n-2; i++)
		dp[i][i+2] = q[i] * q[i+1] * q[i+2];

	for(int k = 0; k < n; k++){
		for(int i = 0; i < 2*n; i++){
			dp[i][i+k-1] = 0;
			for(int j = i; j < i+k; j++){
				int sum = q[i] * q[j] * q[i+k-1];
				if( sum + dp[i][j] + dp[j][i+k-1] > dp[i][i+k-1])
					dp[i][i+k-1] = sum + dp[i][j] + dp[j][i+k-1];
			}
		}
	}

	int max = 0;
	for(int i = 0; i <= 2*n-(n+1); i++)
		if(dp[i][i+n+1] > max)
			max = dp[i][i+n+1];

	cout << max << endl;

	return 0;
}