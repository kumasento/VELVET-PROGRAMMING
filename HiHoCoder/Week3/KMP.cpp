
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getFail(string P, vector<int> &f)
{
    int m = P.length();
    f[0] = 0, f[1] = 0;
    for (int i = 1; i < m; i++)
    {
        int j = f[i];
        while (j && P[i] != P[j]) j = f[j];
        f[i+1] = P[i] == P[j] ? j+1 : 0;
    }
}

int find(string T, string P, vector<int> &f)
{
    int n = T.length(), m = P.length();
    getFail(P, f);

    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j && P[j] != T[i]) j = f[j];
        if (P[j] == T[i]) j++;
        if (j == m) count ++;
    }

    return count;
}

int main()
{
    freopen("testcase", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string P, T; cin>>P>>T;
        vector<int> f(P.length()+2);

        cout << find(T, P, f) << endl;
    }

    return 0;
}
