#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	freopen("1017.in", "r", stdin);
	int N, K; cin>>N>>K;
	string num; cin>>num;

	long long dp[N+1][K+1]; memset(dp, 0, sizeof(dp));
	for(int k = 0; k <= K; k++){
		for(int s = 0; s < N; s++){
			if(k == 0) dp[s][k] = atoi(num.substr(s, N-s).c_str());
			else{
				dp[s][k] = 0;
				for(int t = s+1; t < N; t++)
					dp[s][k] = max(dp[s][k], atoi(num.substr(s, t-s).c_str()) * dp[t][k-1]);
			}
		}
	}
	cout << dp[0][K] << endl;
	return 0;
}