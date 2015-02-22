
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <algorithm>

#define MAXN 200010
#define MAXC 20

using namespace std;

int dp[MAXN][MAXC+1];

struct Node { vector<int> child_list; };

int minGifting(int v, int c, vector<Node *> &nodes, int N)
{
    if (dp[v][c] != -1)
        return dp[v][c];
    int sum = c;
    cout << v << endl;
    for (int i = 0; i < nodes[v]->child_list.size(); i++)
    {
        int min_val = INT_MAX;
        for (int ci = 1; ci <= MAXC; ci ++)
            if (ci != c)
                 min_val = min(min_val,
                         minGifting(nodes[v]->child_list[i], ci, nodes, N));
        sum += min_val;
    }
    dp[v][c] = sum;
    return sum;
}

int main()
{
    //freopen("D.CorporateGifting.dat", "r", stdin);
    freopen("gifting.full.in", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N; cin >> N;
        vector<Node *> nodes(N+1);
        for (int i = 0; i <= N; i++)
            nodes[i] = new Node();
        for (int i = 0; i < N; i++)
        {
            int parent_idx; cin >> parent_idx;
            nodes[parent_idx]->child_list.push_back(i+1);
        }

        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for (int i = 1; i <= MAXC; i++)
            ans = min(minGifting(1, i, nodes, N), ans);
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
