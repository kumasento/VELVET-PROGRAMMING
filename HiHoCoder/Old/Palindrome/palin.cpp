#include <cstdio>
#include <iostream>

#include "enum_palin.h"
#include "center_palin.h"
#include "dp_palin.h"

#define MAXN 100010

using namespace std;

int main() {
    freopen("palin.txt", "r", stdin);

    int n; cin >>n;
    for (int i = 0; i < n; i++) {
        char origin_string[MAXN];
        scanf("%s", origin_string);

        printf("%s\n", origin_string); 
        printf("==> %d\n", enum_palin(origin_string));
        printf("==> %d\n", center_palin(origin_string));
        printf("==> %d\n", dp_palin(origin_string));
    }
    
    return 0;
}
