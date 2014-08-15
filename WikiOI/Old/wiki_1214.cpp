#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAXN 110

using namespace std;

struct seg{
	int l, r;
} segs[MAXN];

int cmp(const void *a1, const void *a2){
	seg *s1 = (seg *)a1, *s2 = (seg *)a2;
	if(s1->r == s2->r) return s1->l - s2->l;
	else return s1->r - s2->r;
}

int main(){
	freopen("1214.in", "r", stdin);
	int N; cin>>N;
	for(int i = 0; i < N; i++){
		int i1, i2; cin>>i1>>i2;
		segs[i].l = min(i1, i2);
		segs[i].r = max(i1, i2);
	}
	qsort(segs, N, sizeof(segs[0]), cmp);

	int tmp = segs[0].r;
	int cnt = 1;
	for(int i = 1; i < N; i++){
		if(segs[i].l >= tmp){
			tmp = segs[i].r;
			cnt ++;
		}
	}

	cout << cnt << endl;
	return 0;
}