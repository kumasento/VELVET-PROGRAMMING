
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 210

using namespace std;

int disjoint_set[MAXN];
int Find(int x)
{
    return (disjoint_set[x] != x)
        ? disjoint_set[x] = Find(disjoint_set[x])
        : x;
}
void Union(int x, int y)
{
    int rx = Find(x);
    int ry = Find(y);
    if (rx != ry)
        disjoint_set[rx] = ry;
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    int hn;

    // init
    int sum = n + m;
    for (int i = 0; i < sum; i++) disjoint_set[i] = i;
    for (int i = 0; ; i++)
        if (i != 0 && (i % n == 0 && i % m == 0))
            break;
        else
        {
            int bi = i % n;
            int gi = i % m + n;
            Union(bi, gi);
        }

    bool r_list[sum];
    memset(r_list, 0, sizeof(r_list));
    scanf("%d", &hn);
    for (int i = 0; i < hn; i++)
    {
        int idx; scanf("%d", &idx);
        r_list[Find(idx)] = true;
    }
    scanf("%d", &hn);
    for (int i = 0; i < hn; i++)
    {
        int idx; scanf("%d", &idx);
        idx = idx + n;
        r_list[Find(idx)] = true;
    }

    bool ok = true;
    for (int i = 0; i < sum && ok; i++)
        if (!r_list[Find(i)])
            ok = false;
    printf("%s\n", (ok) ? "Yes" : "No");

    return 0;
}
