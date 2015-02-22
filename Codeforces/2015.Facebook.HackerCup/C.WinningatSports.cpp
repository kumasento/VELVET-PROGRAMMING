
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STRLEN 10
#define MAXN 2010
#define MOD 1000000007

using namespace std;

long long f[MAXN][MAXN];
long long nf[MAXN][MAXN];

long long stressful(int x, int y, int fx, int fy)
{
    if (x < 0 || y < 0)
        return 0;
    if (f[x][y] != -1)
        return f[x][y];
    if (x <= y || y == fy)
    {
        long long sum = 0;
        sum += stressful(x-1, y, fx, fy); sum %= MOD;
        sum += stressful(x, y-1, fx, fy); sum %= MOD;
        f[x][y] = sum;
        return sum;
    }
    f[x][y] = 0;
    return 0;
}

long long stressfree(int x, int y, int fx, int fy)
{
    if (x < 0 || y < 0)
        return 0;
    if (nf[x][y] != -1)
        return nf[x][y];
    if (x > y)
    {
        long long sum = 0;
        sum += stressfree(x-1, y, fx, fy); sum %= MOD;
        sum += stressfree(x, y-1, fx, fy); sum %= MOD;
        nf[x][y] = sum;
        return sum;
    }
    nf[x][y] = 0;
    return 0;
}

int main()
{
    freopen("C.WinningatSports.dat", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        char str[STRLEN];
        memset(str, 0, sizeof(str));
        cin >> str;
        char xstr[STRLEN], ystr[STRLEN];
        memset(xstr, 0, sizeof(xstr));
        memset(ystr, 0, sizeof(ystr));
        int idx = 0;
        for (; idx < strlen(str) && str[idx] != '-'; idx ++);
        strncpy(xstr, str, idx);
        strncpy(ystr, str+idx+1, strlen(str)-idx-1);

        int x = atoi(xstr);
        int y = atoi(ystr);

        memset(f, -1, sizeof(f));
        memset(nf, -1, sizeof(nf));
        f[0][1] = 1;
        nf[1][0] = 1;
        int s1 = stressfree(x, y, x, y);
        int s2 = stressful(x, y, x, y);
        printf("Case #%d: %d %d\n", t, s1, s2);
    }
    return 0;
}
