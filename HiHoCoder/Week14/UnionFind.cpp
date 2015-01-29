
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MAXN 100005

using namespace std;

int pa[MAXN];
int findset(int x) { return (x == pa[x]) ? x : pa[x] = findset(pa[x]); }

int main()
{
    freopen("testcase", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        pa[i] = i;
    
    int count = 0;
    map<string, int> hash;
    for (int i = 0; i < N; i++)
    {
        // deal with input
        int op;
        string s1, s2;
        cin >> op >> s1 >> s2;

        if (hash.find(s1) == hash.end()) hash[s1] = count ++;
        if (hash.find(s2) == hash.end()) hash[s2] = count ++;
    
        int x = hash[s1], y = hash[s2];
        if (op == 0) // do union
        {
            int rx = findset(x);
            int ry = findset(y);
            pa[rx] = ry;
        }
        else 
        {
            if (findset(x) == findset(y))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    return 0;
}
