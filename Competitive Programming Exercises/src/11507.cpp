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
 
#define AXIS 6
#define LEN 3

void opt_parser(char origins[AXIS][LEN], char opts[LEN]) {
    if (!strcmp(opts, "No")) return ;
    else if (!strcmp(opts, "+z")) {
        swap(origins[0], origins[4]);
        swap(origins[1], origins[5]);
        swap(origins[1], origins[0]);
    }
    else if (!strcmp(opts, "-z")) {
        swap(origins[0], origins[4]);
        swap(origins[1], origins[5]);
        swap(origins[4], origins[5]);
    }
    else if (!strcmp(opts, "+y")) {
        swap(origins[0], origins[2]);
        swap(origins[1], origins[3]);
        swap(origins[0], origins[1]);
    }
    else if (!strcmp(opts, "-y")) {
        swap(origins[0], origins[2]);
        swap(origins[1], origins[3]);
        swap(origins[2], origins[3]);
    }
}

char ORIGIN[AXIS][LEN] = {"+x", "-x", "+y", "-y", "+z", "-z"};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../data/11507.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);

    while (n != 0) {
        char origin[AXIS][LEN] = {"+x", "-x", "+y", "-y", "+z", "-z"};
        char opts[n-1][LEN];
        for (int i = 0; i < n-1; i++) scanf("%s", opts[i]);
        for (int i = 0; i < n-1 ; i++) opt_parser(origin, opts[i]);

        for (int i = 0; i < AXIS; i++) 
            if (!strcmp(origin[i], "+x"))
                printf("%s\n", ORIGIN[i]);
        scanf("%d", &n);
    }
#ifdef DEBUG
    
#endif
   return 0;
}
