#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAXN 51

using namespace std;

int main(){
	freopen("1126.in", "r", stdin);
	int m, n; cin>>m>>n;
	int M[m+1][n+1]; memset(M, 0, sizeof(M));
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin>>M[i][j];
	cout << m << ' ' << n << endl;
	
	int ; 
	memset(dp, 0, sizeof(dp));
	dp[m][n-1][m-1][n] = M[m][n-1] + M[m-1][n];
	int cnt = 0;
	
	//iterate from the bottom border, right -> left
	for(int k = 2; k < m; k++){
		for(int i = 0; i <= k; i++){
			for(int j = i+1; j <= k; j++){
				// now we are sure of what we are going to calculate
				int x1 = m-k+i, y1 = n-i; // 1 is decided by i
				int x2 = m-k+j, y2 = n-j; // 2 is decided by j
				dp[x1][y1][x2][y2] = 0;
				// both right
				if(x1+1 <= m && x2+1 <= m) dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1+1][y1][x2+1][y2]);
				// both down
				if(y1+1 <= n && y2+1 <= n) dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1+1][x2][y2+1]);
				// 1 right 2 down
				if(x1+1 <= m && y2+1 <= n && x1+1 != x2 && y1 != y2+1)
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1+1][y1][x2][y2+1]);
				// 1 down 2 right
				if(y1+1 <= n && x2+1 <= m && y1+1 != y2 && x1+1 != x2)
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1+1][x2+1][y2]);
				dp[x1][y1][x2][y2] += M[x1][y1] + M[x2][y2];
			}
		}
	}
	//iterate from the leftmost border, bottom -> up
	for(int k = 2; k < m; k++){
		for(int i = 0; i <= k; i++){
			for(int j = i+1; j <= k; j++){
				// now we are sure of what we are going to calculate
				int x1 = 1+i, y1 = n-k-i; // 1 is decided by i
				int x2 = 1+j, y2 = n-k-j; // 2 is decided by j
				dp[x1][y1][x2][y2] = 0;
				// both right
				if(x1+1 <= m && x2+1 <= m) dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1+1][y1][x2+1][y2]);
				// both down
				if(y1+1 <= n && y2+1 <= n) dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1+1][x2][y2+1]);
				// 1 right 2 down
				if(x1+1 <= m && y2+1 <= n && x1+1 != x2 && y1 != y2+1)
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1+1][y1][x2][y2+1]);
				// 1 down 2 right
				if(y1+1 <= n && x2+1 <= m && y1+1 != y2 && x1+1 != x2)
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1+1][x2+1][y2]);
				dp[x1][y1][x2][y2] += M[x1][y1] + M[x2][y2];
			}
		}
	}
	cout << dp[2][1][1][2] << endl;
	
	return 0;
}