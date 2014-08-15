#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

bool is_horse(int x, int y, int X, int Y){
	return (abs(x-X) == 2 && abs(y-Y) == 1) ||
		   (abs(x-X) == 1 && abs(y-Y) == 2) ||
		   (x == X && y == Y);
}

int main(){
	freopen("1010.in", "r", stdin);
	int n, m, X, Y;
	cin>>n>>m>>X>>Y;

	long long dp[m+n+10][m+1]; memset(dp, 0, sizeof(dp));
	if(is_horse(n, m, X, Y)) cout << 0 << endl;
	else{
		// k is the total pace 
		dp[n][m] = 1;
		for(int k = 1; k <= m+n; k++){
			// i is the up pace
			//cout << k << endl;
			for(int i = 0; i <= k; i++){
				if(i <= m && (k-i) <= n){
					int y = m-i, x = n - (k-i);
					if(is_horse(x,y,X,Y)) dp[x][y] = 0;
					else{
						if(x+1 <= n) dp[x][y] += dp[x+1][y];
						if(y+1 <= m) dp[x][y] += dp[x][y+1];
						//cout << x << ' ' << y << ' ' << dp[x][y] << endl;
					}
				}
			}
		}
		cout << dp[0][0] << endl;
	}
	return 0;
}