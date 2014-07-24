#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define MAXN 20

using namespace std;

int mat[MAXN][MAXN];
int mat_cp[MAXN][MAXN];

int get_sum(int x, int y, int n){
	int sum = 0;
	if(x-1 >= 0) sum += mat_cp[x-1][y];
	if(y-1 >= 0) sum += mat_cp[x][y-1];
	if(x+1 < n) sum += mat_cp[x+1][y];
	if(y+1 < n) sum += mat_cp[x][y+1];
	return sum;
}

int main(){
	freopen("11464.in", "r", stdin);
	int N; cin>>N;
	for(int I = 1; I <= N; I++){
		int n; cin>>n;
		for(int x = 0; x < n; x++)
			for(int y = 0; y < n; y++)
				cin>>mat[x][y];

		int min_cnt = n * n + 10;
		for( int T = 0; T <= ((1<<n)-1); T++ ){
			int cnt = 0; int ok = 1;
			for(int x = 0; x < n; x++)
				for(int y = 0; y < n; y++)
					mat_cp[x][y] = mat[x][y];

			for(int i = 0; i < n; i++){
				if( ((T >> i) & 1) == 1 ){
					if( mat_cp[0][i] == 1){
						ok = 0;
						break;
					}
					else{
						cnt ++;
						mat_cp[0][i] = 1;
					}
				}
			}

			if(ok == 0) continue;

			for(int i = 1; i < n; i++){
				for(int j = 0; j < n; j++){
					int sum = get_sum(i-1, j, n);
					if(sum % 2 != 0){
						if(mat_cp[i][j] == 1){
							ok = 0;
							break;
						}
						else{
							cnt ++;
							mat_cp[i][j] = 1;
						}
					} 
				}
			}

			if(ok == 0) continue;

			for(int i = 0; i < n; i++){
				int sum = get_sum(n-1, i, n);
				if(sum % 2 != 0){
					ok = 0;
					break;
				}
			}

			if(ok == 0) continue;

			if(cnt < min_cnt)
				min_cnt = cnt;
		}
		printf("Case %d: %d\n", I, (min_cnt == n*n + 10) ? -1 : min_cnt);
	}
	return 0;
}