#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
 
#define DEBUG
#define Rep(i,a) for(int i=0; i<a; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/12247.txt", "r", stdin);
#endif

    int A, B, C, X, Y;
    while (cin>>A>>B>>C>>X>>Y) {
        if (A == 0) break;
        
        set<int> card_set;
        card_set.insert(A);
        card_set.insert(B);
        card_set.insert(C);
        card_set.insert(X);
        card_set.insert(Y);

        int seq[3] = {A, B, C};
        sort(seq, seq + 3, greater<int>());

        int big = (X > Y) ? X : Y;
        int small = (X > Y) ? Y : X;

        int val = -1;
        if (big > seq[0]) {
            if (small > seq[0]) { for (int i = 1; i <= 52 && val == -1; i++) if (card_set.find(i) == card_set.end()) val = i; }
            else if (small < seq[0] && small > seq[1]) { for (int i = seq[1] + 1; i <= 52 && val == -1; i++) if (card_set.find(i) == card_set.end()) val = i; }
            else if (small < seq[1]) { for (int i = seq[0] + 1; i <= 52 && val == -1; i++) if (card_set.find(i) == card_set.end()) val = i; }
        }
        else if (big < seq[0] && big > seq[1]) {
            if (small > seq[1]) { for (int i = seq[1] + 1; i <= 52 && val == -1; i++) if (card_set.find(i) == card_set.end()) val = i; }
        }
        cout << val << endl;
    }

#ifdef DEBUG
    
#endif
   return 0;
}
