#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define MAXN 510
#define MAXW 10010

#define MAX_INT 0x3f3f3f3f

using namespace std;

int P[MAXN], W[MAXN];
int dp[MAXW];

int main(){
	freopen("1384.in","r",stdin);

	int T; cin >> T;
	while(T--){
		int E, F; scanf("%d%d", &E, &F);
		int N; cin>>N; 
		for(int i = 0; i < N; i++)
			scanf("%d%d", &P[i], &W[i]);

		dp[0] = 0;
		for(int i = 1; i <= MAXW; i++)
			dp[i] = MAX_INT;
		for(int i = 0; i < N; i++){
			for(int v = W[i]; v <= F-E; v++){
				dp[v] = min(dp[v-W[i]] + P[i], dp[v]);
			}
		}

		if(dp[F-E] == MAX_INT)
			cout << "This is impossible." << endl;
		else
			cout << "The minimum amount of money in the piggy-bank is " << dp[F-E] << "." << endl;
	}

	return 0;
}