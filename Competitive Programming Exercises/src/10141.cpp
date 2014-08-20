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
using namespace std;
 
#define DEBUG
#define Rep(i,a) for(int i=0; i<a; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define VE vector<int>
#define SZ size()
#define PB push_back
 

#define MAXLEN 100

int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/10141.txt", "r", stdin);
#endif
    
    int n, p; 
    int cnt = 1;
    int has_start = 0;
    while (cin>>n>>p) {
        if (n==0 && p==0) break;

        getchar();
        char req[n][MAXLEN];
        for (int i = 0; i < n; i++) cin.getline(req[i], MAXLEN, '\n');

        char prop_name[p][MAXLEN];
        double prop_price[p];
        int prop_num[p];
        for (int i = 0; i < p; i++) {
            cin.getline(prop_name[i], MAXLEN, '\n');
            cin >> prop_price[i];
            cin >> prop_num[i];
            getchar();
            for (int j = 0; j < prop_num[i]; j++){
                char str[MAXLEN];
                cin.getline(str, MAXLEN, '\n');
            }

        }
        if (has_start) cout << endl;
        else has_start = 1;
        cout << "RFP #" << cnt << endl;
        // find the largest compliance
        int max = 0;
        for (int i = 0; i < p; i++) 
            if (prop_num[i] > max)
                max = prop_num[i];

        int idx = 0; 
        int start = 0;
        double min = 0.0; 
        for (int i = 0; i < p; i++) 
            if (prop_num[i] == max) { 
                if (!start) {
                    start = 1;
                    idx = i;
                    min = prop_price[i];
                }
                else if (prop_price[i] < min) {
                    min = prop_price[i];
                    idx = i;
                }
            }

        cout << prop_name[idx] << endl;

        cnt ++;
    }
#ifdef DEBUG
    
#endif
   return 0;
}
