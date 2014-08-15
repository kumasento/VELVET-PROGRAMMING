#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("1014.in", "r", stdin);

	int V; cin >> V;
	int N; cin >> N;
	int W[N]; for(int i = 0; i < N; i++) cin >> W[i];
	int dp[V+1]; memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		for(int v = V; v >= W[i]; v--){
			dp[v] = max(dp[v-W[i]]+W[i], dp[v]);
		}
	}
	cout << V-dp[V] << endl;

	return 0;
}