
#include <iostream>
#include <string>
#include <vector>

#define SIGMA_SIZE 26
#define MAXN 1000010

using namespace std;

struct Trie
{
    int ch[MAXN][SIGMA_SIZE];
    int val[MAXN];
    int sz;
    Trie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
    int idx(char c) { return c - 'a'; }

    void insert(string s)
    {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (!ch[u][c]) // need a new node
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            val[ch[u][c]] ++; // update along the route;
            
            u = ch[u][c]; // current node to next node
        }
    }
};

int main()
{
    freopen("testcase", "r", stdin);

    int n; cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
        cin >> dict[i];

    Trie trie;
    for (int i = 0; i < n; i++)
        trie.insert(dict[i]);

    int m; cin >> m;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;

        // query
        int res = 0;
        bool exist = true;
        int u = 0, n = s.length();
        for (int i = 0; i < n && exist; i++)
        {
            int c = trie.idx(s[i]);
            if (!trie.ch[u][c])
                exist = false;
            u = trie.ch[u][c]; // move down
        }
        if (exist)
            res = trie.val[u];
        cout << res << endl;
    }

    return 0;
}
