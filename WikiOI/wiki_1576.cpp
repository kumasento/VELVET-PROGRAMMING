#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	freopen("1576.in", "r", stdin);
	int n; cin>>n;
	int seq[n]; memset(seq, 0, sizeof(seq));
	for(int i = 0; i < n; i++)
		cin >> seq[i]; 

	int dp[n]; memset(dp, 0, sizeof(dp));
	for(int i = n-1; i >= 0; i--){
		int max = 0;
		for(int j = i + 1; j < n; j++){
			if(seq[j] >= seq[i] && dp[j] > max )
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	int tmp_max = 0;
	for(int i = 0; i < n; i++)
		if(tmp_max < dp[i])
			tmp_max = dp[i];
	cout << tmp_max << endl;
	return 0;
}