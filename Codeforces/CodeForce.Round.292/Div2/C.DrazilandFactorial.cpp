
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int n; scanf("%d", &n);
    char num[n+1]; scanf("%s", &num);
    char ans[5*n];
    int buckets[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < n; i++)
    {
        int idx = num[i] - '0';
        switch (idx)
        {
            case 0:
            case 1:
                break;
            case 2:
                buckets[2] ++;
                break;
            case 3:
                buckets[3] ++;
                break;
            case 4:
                buckets[2] += 2;
                buckets[3] ++;
                break;
            case 5:
                buckets[5] ++;
                break;
            case 6:
                buckets[3] ++;
                buckets[5] ++;
                break;
            case 7:
                buckets[7] ++;
                break;
            case 8:
                buckets[7] ++;
                buckets[2] += 3;
                break;
            case 9:
                buckets[7] ++;
                buckets[3] += 2;
                buckets[2] ++;
                break;
        }
    }
    int cnt = 0;
    for (int i = 9; i >= 2; i--)
        for (int j = 0; j < buckets[i]; j++)
            ans[cnt++] = i + '0';
    ans[cnt] = '\0';

    printf("%s\n", ans);

    return 0;
}
