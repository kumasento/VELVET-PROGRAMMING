#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 210

using namespace std;

struct segment{
	int l, r;
} q[MAXN];

int main(){
	freopen("1154.in", "r", stdin);
	int n; cin>>n;
	memset(q, 0, sizeof(q));
	int seq[n]; memset(seq, 0, sizeof(seq));
	for(int i = 0; i < n; i++)
		cin>>seq[i];
	for(int i = 0; i < 2 * n; i++){
		if(i < n) q[i].l = seq[i];
		else q[i].l = seq[i-n];
	}
	for(int i = 0; i < 2 * n; i++)
		if(i != 2*n-1)
			q[i].r = q[i+1].l;
	/*
	for(int i = 0; i < 2*n; i++)
		printf("%d %d\n", q[i].l, q[i].r);
	*/
	int dp[2 * n][2 * n]; memset(dp, 0, sizeof(dp));

	/*
	 * The basic idea in this algorithm is that:
	 * Because the struture is a ring, so we need to make it a 2n length array
	 * And then, find the n length continuous segment
	 * which has the max value of collision
	 */

	// init
	for(int i = 0; i < 2*n-2; i++)
		dp[i][i+1] = q[i].l * q[i].r * q[i+1].r;

	/*
	 * How to divide the ring depends on the range of j
	 */

	for(int k = 3; k <= n; k++){
		for(int i = 0; i < 2*n-k; i++){
			//cout << i << ' ' << i+k << endl;
			dp[i][i+k-1] = 0;
			for(int j = i+1; j < i+k; j++){
				int sum = q[i].l * q[j].l * q[i+k-1].r;
				//printf("i:%d j:%d i+k-1:%d\n", i, j, i+k-1 );
				if( sum + dp[i][j-1] + dp[j][i+k-1] > dp[i][i+k-1])
					dp[i][i+k-1] = sum + dp[i][j-1] + dp[j][i+k-1];
			}
			//cout << dp[i][i+k-1] << endl;
		}
	}

	int max = 0;
	for(int i = 0; i < 2*n-n; i++)
		if(dp[i][i+n-1] > max)
			max = dp[i][i+n-1];
	cout << max << endl;
	
	return 0;
}