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
#define Rep(i,a) for(int i=0; i<a; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/11799.txt", "r", stdin);
#endif
    int T; cin>>T;
    for (int i = 0; i < T; i++) {
        int N; cin>>N;
        int Max = 0;
        for (int j = 0; j < N; j++) {
            int t; cin>>t;
            if (t > Max) 
                Max = t;
        }
        cout << "Case " << i + 1 << ": " << Max << endl;
    }
#ifdef DEBUG
    
#endif
   return 0;
}
