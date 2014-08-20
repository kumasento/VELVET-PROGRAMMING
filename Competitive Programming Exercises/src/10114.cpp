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
 
#define MONTH 12
#define MAXN 100

int main() {
#ifndef ONLINE_JUDGE    
    freopen("../data/10114.txt", "r", stdin);
#endif
    int dur;
    double down, loan;
    int dep_num;
    while (cin>>dur>>down>>loan>>dep_num) {
        if (dur < 0) break;
        
        int dep_mon[dep_num];
        double dep_val[dep_num];
        for (int i = 0; i < dep_num; i++) 
            cin >> dep_mon[i] >> dep_val[i];
        
        double initial_val = (loan + down) * (1-dep_val[0]);
        double pay = loan / dur;
        double dep_by_mon[dur];

        int current = 0;
        for (int i = 1; i < dep_num; i++) 
            for (; current < dep_mon[i] - 1; current ++)
                dep_by_mon[current] = dep_val[i-1];

        for (; current < dur; current ++)
            dep_by_mon[current] = dep_val[dep_num-1];

        double end_val = initial_val;
        double pay_val = loan;
        int month;
        for (month = 0; month <= dur; month ++) {
            /*printf("%.6f %.6f\n", pay_val, end_val);*/
            if (pay_val < end_val) 
                break;
            pay_val -= pay;
            end_val *= (double)(1 - dep_by_mon[month]);
        }
        if (month == 1) cout << "1 month" << endl;
        else cout << month << " months" << endl;
    }

#ifdef DEBUG
    
#endif
   return 0;
}
