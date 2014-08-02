#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define SQUARE(x) ((x) * (x))

#define MAXN 100
#define MAXL 10000

using namespace std;

int n, k, p, d;

int link[MAXL];
int vis[MAXN];

struct p{int x, y;} AP[MAXN], T[MAXN];
struct Time{
	int h, m;
} g[MAXN][MAXN], times[MAXL];

int cnt = 0;
void addTime(double sec, int m, int n){
	int min = ((int)sec)/60 + g[m][n].m;
	int hour = min/60;
	g[m][n].h += hour, g[m][n].m = min%60;
	times[cnt].h = g[m][n].h;
	times[cnt].m = g[m][n].m;
	cnt++;
}
int cmp(const void *a, const void *b){
	Time *p1 = (Time *)a, *p2 = (Time *)b;
	if(p1->h == p2->h) return p1->m - p2->m;
	else return p1->h - p2->h;
}
int bsearch(int d){
	int 
}

int main(){
	freopen("data_1534.in","r",stdin);
	while(scanf("%d%d%d%d", &n, &k, &p, &d) == 4 && !(n==0 && k==0 && p==0 && d==0)){
		cnt = 0;
		for(int i = 0; i < n; i++)
			scanf("%d%d", &AP[i].x, &AP[i].y);
		for(int i = 0; i < k; i++)
			scanf("%d%d", &T[i].x, &T[i].y);
		for(int i = 0; i < p; i++){
			int h, m, f, t, s;
			scanf("%d%d%d%d%d", &h, &m, &f, &t, &s);
			for(int j = 0; j < k; j++){
				g[i][j].h = h, g[i][j].m = m;
				double sec = sqrt((AP[f].x-T[j].x)*(AP[f].x-T[j].x)+
					(AP[f].y-T[j].y)*(AP[f].y-T[j].y))/s*1000;
				//cout << sec << endl;
				addTime(sec, i, j);
			}
		}
		qsort(times, cnt, sizeof(Time), cmp);
		int bsearch(int d);
		
	}
	return 0;
}