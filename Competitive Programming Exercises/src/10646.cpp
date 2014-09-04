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

#define CARDS 52
#define START 25 

int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/10646.txt", "r", stdin);
#endif

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        vector<string> cards(CARDS);
        for (int i = 0; i < CARDS; i++)
            cin >> cards[i];
        
        int Y = 0;
        int last = 0;
        int count = 0;
        for (int i = START-1; i >= 0 && count < 3;) {
            char card_name = cards[i][0];
            int card_val = 0;
            if (card_name - '2' <= 7 && card_name - '2' >= 0)
                card_val = card_name - '0';
            else 
                card_val = 10;
            
            int X = card_val;
            Y += X;
            i -= 10 - X + 1;
            count ++;
            last = i;
        }
       
        string res = "";
        if (Y > last + 1) res = cards[START + Y - last - 2];
        else res = cards[Y-1];

        cout << "Case " << t+1 << ": " << res << endl;
    }

#ifdef DEBUG
    
#endif
   return 0;
}
