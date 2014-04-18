#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 110

using namespace std;

int Mat[MAXN][MAXN];

int f(int *vec, int idx, int M, int N, int *MARK){
	if(idx == M){
		int SUM = 0;
		for(int k = 0; k < M; k++){
			int ELEM = Mat[k][vec[k]];
			SUM += ELEM;
		}
		return SUM;
	}

	int MIN = 1100000;
	for(int i = 0; i < N; i++){
		if(!MARK[i]){
			MARK[i] = 1;
			vec[idx+1] = i;
			int ret = f(vec, idx+1, M, N, MARK);
			if(ret < MIN)
				MIN = ret;
			vec[idx+1] = -1;
			MARK[i] = 0;
		}
	}
	return MIN;
}

int main(){
	freopen("Q3.in", "r", stdin);

	int T, m, n;
	scanf("%d", &T);
	int index = 1;
	while(scanf("%d%d", &m, &n) == 2){
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &Mat[i][j]);

		int VEC[m]; memset(VEC, 0, sizeof(VEC));
		int MARK[m]; memset(MARK, 0, sizeof(MARK));
		int ANS = f(VEC, 0, m, n, MARK);

		printf("Case %d: %d\n", index, ANS);
		index++;
	}

	return 0;
}