#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	//freopen("B.in", "r", stdin);
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	//int mat[n][m]; memset(mat, 0, sizeof(mat));
	int E[n][m]; memset(E, 0, sizeof(E));
	int U[n]; memset(U, 0, sizeof(U));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int tmp_val; scanf("%d", &tmp_val);
			if(tmp_val)
				E[i][U[i]++] = j;
		}
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < U[i]; j++)
			cout << E[i][j] << ' ';
		cout << endl;
	}
	*/
	
	int V[n]; memset(V, 0, sizeof(V));
	int Visited[m]; memset(Visited, 0, sizeof(Visited));
	int Used[n][m]; memset(Used, 0, sizeof(Used));
	
	for(int i = 0; i < k; i++){
		int x, y; scanf("%d%d", &x, &y);
		x--, y--;
		Used[x][y] ++;
		Visited[y] ++;
	}
	for(int i = 0; i < n; i++){
		int tmp_sum = 0;
		for(int j = 0; j < U[i]; j++)
			tmp_sum += (Visited[E[i][j]] - Used[i][E[i][j]]);
		printf("%d ", tmp_sum);
	}
	printf("\n");
	return 0;
}