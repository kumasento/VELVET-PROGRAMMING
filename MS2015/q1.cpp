
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define LEN 10

using namespace std;

int isYear(int y) {
    return (!(y % 4) && (y % 100)) || !(y % 400);
}
int getMonth(char *ms) {
    if (!strcmp(ms, "January"))         return 1;
    else if (!strcmp(ms, "February"))   return 2;
    else if (!strcmp(ms, "March"))      return 3;
    else if (!strcmp(ms, "April"))      return 4;
    else if (!strcmp(ms, "May"))        return 5;
    else if (!strcmp(ms, "June"))       return 6;
    else if (!strcmp(ms, "July"))       return 7;
    else if (!strcmp(ms, "August"))     return 8;
    else if (!strcmp(ms, "September"))  return 9;
    else if (!strcmp(ms, "October"))    return 10;
    else if (!strcmp(ms, "November"))   return 11;
    else if (!strcmp(ms, "December"))   return 12;
    return 0;
}

int numOfYear(int y) {


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    char ms1[LEN], ms2[LEN];
    char ds1[LEN], ds2[LEN];
    int m1, m2;
    int d1, d2;
    int y1, y2;

    for (int t = 0; t < T; t++) {
        scanf("%s%s%d", ms1, ds1, &y1);
        scanf("%s%s%d", ms2, ds2, &y2);
        ds1[strlen(ds1)-1] = '\0';
        ds2[strlen(ds2)-1] = '\0';
        m1 = getMonth(ms1), m2 = getMonth(ms2);
        d1 = atoi(ds1), d2 = atoi(ds2);


    }
    return 0;
}
