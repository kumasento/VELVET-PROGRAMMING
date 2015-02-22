#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define CEIL_DIV(x, a) ((x)/(a) + ((x)%(a)+(a)-1)/(a))

using namespace std;

int main() {
    //freopen("../data/1A.txt", "r", stdin);
    
    int n, m, a; scanf("%d%d%d", &n, &m, &a);
    long h = (long) CEIL_DIV(n, a);
    long w = (long) CEIL_DIV(m, a);
    long result = h * w;

    printf("%ld\n", result);

    return 0;
}
