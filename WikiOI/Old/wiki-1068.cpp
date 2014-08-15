#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("1068.in", "r", stdin);
	int N, M; cin>>N>>M;
	int Cards[N+1]; memset(Cards, 0, sizeof(Cards));
	for(int i = 1; i <= N; i++)
		cin>>Cards[i];
	int Cont[4] = {0,0,0,0};
	for(int i = 0; i < M; i++){
		int tmp; cin>>tmp;
		Cont[tmp-1] ++;
	}

	int dp[Cont[0]+1][Cont[1]+1][Cont[2]+1][Cont[3]+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = Cards[1];
	for(int i = 0; i <= Cont[0]; i++){
		for(int j = 0; j <= Cont[1]; j++){
			for(int k = 0; k <= Cont[2]; k++){
				for(int t = 0; t <= Cont[3]; t++){
					if(i >= 1) dp[i][j][k][t] = max(dp[i-1][j][k][t] + Cards[1+i+j*2+k*3+t*4], dp[i][j][k][t]);
					if(j >= 1) dp[i][j][k][t] = max(dp[i][j-1][k][t] + Cards[1+i+j*2+k*3+t*4], dp[i][j][k][t]);
					if(k >= 1) dp[i][j][k][t] = max(dp[i][j][k-1][t] + Cards[1+i+j*2+k*3+t*4], dp[i][j][k][t]);
					if(t >= 1) dp[i][j][k][t] = max(dp[i][j][k][t-1] + Cards[1+i+j*2+k*3+t*4], dp[i][j][k][t]);
				}
			}
		}
	}
	cout << dp[Cont[0]][Cont[1]][Cont[2]][Cont[3]] << endl;
	return 0;
}