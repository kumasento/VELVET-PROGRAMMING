#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	freopen("1220.in", "r", stdin);
	int n; cin>>n;
	int Tower[n][n]; memset(Tower, 0, sizeof(Tower));
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			scanf("%d", &Tower[i][j]);
	int dp[n]; memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++)
		dp[i] = Tower[n-1][i];
	for(int k = 1; k < n; k++)
		for(int j = 0; j < n-k; j++)
			dp[j] = max(dp[j], dp[j+1]) + Tower[n-k-1][j];
	cout << dp[0] << endl;

	return 0;
}