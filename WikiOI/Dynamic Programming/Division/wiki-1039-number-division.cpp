#include <iostream>
#include <cstdio>

#define MAXN 300
#define MAXK 10

#define DEBUG

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int f[MAXN][MAXK]; 
    memset(f, 0, sizeof(f));

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                f[i][j] = f[i-j][j] + f[i-1][j-1];
        }
    }
    cout << f[n][k] << endl;

#ifdef DEBUG
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            printf("(%2d, %2d)=%6d", i, j, f[i][j]);
        }
        printf("\n");
    }
#endif

    return 0;
}
