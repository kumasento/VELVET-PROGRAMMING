
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
int parent_list[MAXN];
int child_num[MAXN];
vector<int> child[MAXN];

int main()
{
    freopen("D.CorporateGifting.dat", "r", stdin);
    //freopen("gifting.full.in", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N; cin >> N;
        memset(dp, 0, sizeof(dp));
        memset(child, 0, sizeof(child));
        memset(child_num, 0, sizeof(child_num));

        for (int i = 1; i <= N; i++)
        {
            int parent_idx; scanf("%d", &parent_idx);
            parent_list[i] = parent_idx;
            child[parent_idx].push_back(i);
            child_num[parent_idx] ++;
        }
        for (int i = 1; i <= N; i++)
            if (!child_num[i])
            { // no outlink
                for (int j = 1; j <= MAXC; j++)
                    dp[i][j] = j;
                int parent_idx = parent_list[i];
                child_num[parent_idx] --;
                while (!child_num[parent_idx])
                {
                    for (int c = 1; c <= MAXC; c++)
                    {
                        dp[parent_idx][c] = c;
                        for (int j = 0; j < child[parent_idx].size(); j++)
                        {
                            int min_val = INT_MAX;
                            int child_idx = child[parent_idx][j];
                            for (int cj = 1; cj <= MAXC; cj++)
                                if (cj != c)
                                    min_val = min(min_val, dp[child_idx][cj]);
                            dp[parent_idx][c] += min_val;
                        }
                    }
                    parent_idx = parent_list[parent_idx];
                    child_num[parent_idx]--;
                }
            }

        int ans = INT_MAX;
        for (int i = 1; i <= MAXC; i++)
            ans = min(ans, dp[1][i]);
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
