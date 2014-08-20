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
    freopen("../data/11727.txt", "r", stdin);
#endif
    int t; cin>>t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i+1 << ": " ;
        int a, b, c;
        cin>>a>>b>>c;
        if (a>b) {
            if (b>c) cout << b << endl;
            else if (a<c) cout << a << endl;
            else cout << c << endl;
        }
        else {
            if (b<c) cout << b << endl;
            else if (a>c) cout << a << endl;
            else cout << c << endl;
        }
    }

#ifdef DEBUG
    
#endif
   return 0;
}
