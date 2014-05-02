#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define MAXN 60

using namespace std;

int main(){
	freopen("1126.in", "r", stdin);
	int m, n; cin>>m>>n;
	int M[m+1][n+1]; memset(M, 0, sizeof(M));
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin>>M[i][j];

	int dp[MAXN][MAXN][MAXN][MAXN]; 
	memset(dp, 0, sizeof(dp));
	dp[m][n-1][m-1][n] = M[m][n-1] + M[m-1][n];
	int cnt = 0;
	int x1 = m, x2 = m-1, y1 = n-1, y2 = n;
	do{
		if(x1 >= 1)
	} while(cnt != 0)
	return 0;
}