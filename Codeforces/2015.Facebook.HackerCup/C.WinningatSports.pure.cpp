
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STRLEN 20
#define MAXN 2010
#define MOD 1000000007

using namespace std;

long long f[MAXN][MAXN];
long long nf[MAXN][MAXN];

int main()
{
    freopen("C.full.dat", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        char str[STRLEN], xstr[STRLEN], ystr[STRLEN];
        memset(str, 0, sizeof(str));
        memset(xstr, 0, sizeof(xstr));
        memset(ystr, 0, sizeof(ystr));
        cin>>str;
        int idx = 0;
        for (; idx < strlen(str) && str[idx] != '-'; idx ++);
        strncpy(xstr, str, idx);
        strncpy(ystr, str+idx+1, strlen(str)-idx-1);

        int x = atoi(xstr);
        int y = atoi(ystr);

        for (int i = 0; i < MAXN; i++)
        {
            memset(f[i], 0, sizeof(f[i]));
            memset(nf[i], 0, sizeof(nf[i]));
        }

        for (int i = 1; i <= y; i++)
            f[0][i] = 1;
        for (int i = 1; i <= x; i++)
            nf[i][0] = 1;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
            {
                nf[i][j] = (i > j)
                    ? ((i >= 1) ? nf[i-1][j] : 0) + ((j >= 1) ? nf[i][j-1] : 0)
                    : 0;
                f[i][j]  = (i <= j || j == y)
                    ? ((i >= 1) ? f[i-1][j] : 0) + ((j >= 1) ? f[i][j-1] : 0)
                    : 0;

                nf[i][j] %= MOD;
                f[i][j] %= MOD;
            }

        f[x][y] = (f[x][y] < 1) ? 1 : f[x][y];
        printf("Case #%d: %d %d\n", t, (int)nf[x][y], (int)f[x][y]);
    }
    return 0;
}
