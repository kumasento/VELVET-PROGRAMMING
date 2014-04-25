#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 100010

using namespace std;

int dp[MAXN][MAXN];

int main(){
	//freopen("Q3.in", "r", stdin);
	int n; cin>>n;
	int seq[n]; memset(seq, 0, sizeof(seq));
	for(int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	
	memset(dp, 0, sizeof(dp));
	int ans = seq[0];
	for(int i = 1; i <= n; i++){
		if(i != 1) ans ^= seq[i-1];
		for(int k = 1; k <= n; k++)
			ans ^= i % k;
	}

	cout << ans << endl;
	return 0;
}