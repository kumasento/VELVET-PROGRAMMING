#include <cstdio>

using namespace std;

int main()
{
    freopen("C.full.dat", "w", stdout);
    int sum = 0;
    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j < i; j++)
        {
            sum ++;
            printf("%d-%d\n", i, j);
        }
    printf("%d\n", sum);
    return 0;
}
