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
    freopen("../data/11559.txt", "r", stdin);
#endif
    int N, B, H, W;
    while (cin>>N>>B>>H>>W) {
        int P[H];
        int A[H][W];
        for (int i = 0; i < H; i++) {
            cin >> P[i];
            for (int j = 0; j < W; j++)
                cin>>A[i][j];
        }

        int Min = B + 10;
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if (A[j][i] >= N) {
                    int C = P[j] * N;
                    if (C <= B && C <= Min)
                        Min = C;
                }
            }       
        }
        if (Min > B) cout << "stay home" << endl;
        else cout << Min << endl;
    }

#ifdef DEBUG
    
#endif
   return 0;
}
