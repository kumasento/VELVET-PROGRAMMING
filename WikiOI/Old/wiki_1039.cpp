#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("1039.in", "r", stdin);
	int N, K; cin>>N>>K;
	int dp[N+1][K+1][N+1]; memset(dp, 0, sizeof(dp));
	for(int k = 0; k <= K; k++){
		for(int s = 0; s < N; s++){
			if(k == 0) 
				for(int d = 1; d <= N; d++)
					dp[s][k][d] = (N-s < d) ? 0 : 1;
			else
				for(int d = 1; d <= N; d++){
					dp[s][k][d] = 0;
					for(int j = s+d; j < N; j++){
						dp[s][k][d] += dp[j][k-1][j-s];
					}
				}
			
		}
	}
	cout << dp[0][K][1] << endl;
	return 0;
}