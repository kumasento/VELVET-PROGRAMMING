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
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/11172.txt", "r", stdin);  
#endif
    int t; cin>>t;
    for (int i = 0; i < t; i++) {
        long a, b;
        cin>>a>>b;
        if (a < b) cout << "<" << endl;
        else if (a > b) cout << ">" << endl;
        else if (a == b) cout << "=" << endl;
    }
    
    
#ifdef DEBUG
    
#endif
   return 0;
}
