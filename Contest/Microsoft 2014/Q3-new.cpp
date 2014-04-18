#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define MAXN 110

using namespace std;

int MAT[MAXN][MAXN]; 

int f(int *VEC, int idx, int M, int N, int *MARK_COL, int *MARK_ROW){
	if(idx == M){
		int SUM = 0;
		
		for(int i = 0; i < M; i++){
			if(VEC[i] != -1)
				SUM += MAT[i][VEC[i]];
		}
		return SUM;
	}

	if(!MARK_ROW[idx]){
		int MIN = 10000000;
		for(int i = 0; i < N; i++){
			if(!MARK_COL[i]){
				MARK_COL[i] = 1;
				VEC[idx] = i;
				int RET = f(VEC, idx+1, M, N, MARK_COL, MARK_ROW);
				if(RET < MIN)
					MIN = RET;

				VEC[idx] = -1;
				MARK_COL[i] = 0;
			}
		}
		return MIN;
	}
	else
		return f(VEC, idx+1, M, N, MARK_COL, MARK_ROW);
}

int main(){
	freopen("Q3.in", "r", stdin);

	int T; cin>>T;
	int m, n;

	int index = 1;
	while(scanf("%d%d", &m, &n) == 2){
		memset(MAT, 0, sizeof(MAT));
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cin>>MAT[i][j];

		int MARK_ROW[m], MARK_COL[n]; 
		memset(MARK_COL, 0, sizeof(MARK_COL));
		memset(MARK_ROW, 0, sizeof(MARK_ROW));

		int SUM = 0;
		//first pass
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(MAT[i][j] <= 0){
					SUM += MAT[i][j];
					MARK_ROW[i] = MARK_COL[j] = 1;
				}
			}
		}
		//second pass
		int VEC[m]; memset(VEC, -1, sizeof(VEC));

		printf("Case %d: %d\n", index, 
			SUM + f(VEC, 0, m, n, MARK_COL, MARK_ROW));
		index++;
	}
	return 0;
}