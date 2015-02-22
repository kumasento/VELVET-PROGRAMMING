
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

#define N 10000010

using namespace std;

bool prime[N];
int primacity[N];

void make_prime()
{
    memset(prime, 1, sizeof(prime));
    memset(primacity, 0, sizeof(primacity));

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < N; i++)
        if (prime[i])
        {
            primacity[i] = 1;
            for (int k = i*2; k < N; k+=i)
                primacity[k] ++, prime[k] = false;
        }
    return;
}

int main()
{
    freopen("A.Homework.dat", "r", stdin);

    make_prime();

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int A, B, K; cin >> A >> B >> K;
        int count = 0;
        for (int i = A; i <= B; i++)
            if (primacity[i] == K)
                count ++;

        printf("Case #%d: %d\n", t, count);
    }

    return 0;
}
