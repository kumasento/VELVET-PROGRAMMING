#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 205;

struct thing {
    int l;
    int r;
}tmp[N];

bool cmp(const thing& a, const thing& b) {
    if (a.l != b.l) return a.l < b.l;
    else    return a.r <  b.r;
}

int main() {
	freopen("data_LA2322.in", "r", stdin);
    int cas, n, L, R, vis[N];
    scanf("%d", &cas);
    while (cas--) {
	int ti = 0, cnt = 0;
	memset(vis, 0, sizeof(vis));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    scanf("%d%d", &L, &R);
	    if (L > R) {
		int t = R;
		R = L;
		L = t;
	    }
	    tmp[i].l = (L + 1) / 2;
	    tmp[i].r = (R + 1) / 2;
	}

	sort(tmp, tmp + n, cmp);

	while (cnt < n) {
	    ti++;
	    int begin = 0;
	    for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		if (tmp[i].l > begin) {
		    begin = tmp[i].r;
		    cnt++;
		    vis[i] = 1;
		}
	    }
	}

	printf("%d\n", ti * 10);
	
    }
    return 0;
}
