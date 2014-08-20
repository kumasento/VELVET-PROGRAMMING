#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define DEBUG
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/11498.txt", "r", stdin);
#endif
    int K; 
    while (cin>>K) {
        if (K == 0) break;
        int X, Y; cin>>X>>Y;
        REP(i, K) {
            int x, y; cin>>x>>y;
            if (x == X || y == Y) cout << "divisa" << endl;
            else if (x > X && y > Y) cout << "NE" << endl;
            else if (x < X && y > Y) cout << "NO" << endl;
            else if (x > X && y < Y) cout << "SE" << endl;
            else if (x < X && y < Y) cout << "SO" << endl;
        }
    }
#ifdef DEBUG
    
#endif
   return 0;
}
