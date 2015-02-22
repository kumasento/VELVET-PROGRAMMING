
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int a, b, s; scanf("%d%d%d", &a, &b, &s);

    int d = abs(a) + abs(b) - s;
    if (d > 0 || (d < 0 && (-d) % 2))
        puts("No");
    else
        puts("Yes");

    return 0;
}
