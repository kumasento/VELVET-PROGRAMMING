#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define MAXN 100 // MAXN: number of points in polygon
#define INF 0x3fffffff

using namespace std;

double f[MAXN][MAXN];
double g[MAXN][MAXN];

int N;
struct p{double x, y;} ps[MAXN];

int main(){
	freopen("TriangleDivid.in", "r", stdin);
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));

	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%lf%lf", &ps[i].x, &ps[i].y);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			g[i][j] = sqrt(pow((ps[i].x-ps[j].x), 2)+pow((ps[i].y-ps[j].y), 2));
		}
	}

	for(int r = 2; r < n-1; r++){
		for(int i = 0; i < n-r; i++){
			if(r == 2) f[i][i+r] = g[i][i+1]

		}
	}

	return 0;
}