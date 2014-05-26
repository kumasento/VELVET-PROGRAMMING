#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAXN 110

using namespace std;

int adj[MAXN][MAXN];

struct seg{
	int l, r;
} Seg[MAXN];
int CmpSeg(const void *a, const void *b){
	seg *s1 = (seg*)a, *s2 = (seg*)b;
	if(s1->r == s2->r)
		return s1->l - s2->l;
	else
		return s1->r - s2->r;
}

bool fa(int *A, int *ans, int n, int m, int i){
	if(i == n){
		for(int k = 0; k < m; k++)
			if(A[k] != 0 && A[k] != 1 && A[k] != -1)
				return false;
		return true;
	}


}

int main(){
	freopen("Q1.in", "r", stdin);
	int n, m; cin>>n>>m;
	int x[n]; 
	for(int i = 0; i < n; i++)
		cin>>x[i];
	sort(x, x+n);
	for(int i = 0; i < m; i++)
		cin>>Seg[i].l>>Seg[i].r;
	qsort(Seg, m, sizeof(Seg[0]), CmpSeg);
	

	return 0;
}