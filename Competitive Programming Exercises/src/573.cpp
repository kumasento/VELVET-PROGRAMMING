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
    freopen("../data/573.txt", "r", stdin); 
#endif
    int H, U, D, F;
    while (cin >> H >> U >> D >> F) {
        if (H == 0) break;
        double fati_n =(double) F * U / 100;
        double height = 0;
        int t = 0;
        while (true) {
            double up = U - t * fati_n;
            if (up < 0) up = 0;
            double end = height + up;
            if (end > H) { cout << "success on day " << t + 1 << endl; break; }
            end -= D;
            if (end < 0) { cout << "failure on day " << t + 1 << endl; break; }
            t++;
            height = end;
        }
    }


#ifdef DEBUG
    
#endif
   return 0;
}
