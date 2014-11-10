#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL        1000010
#define M           '#'
#define MIN(x,y)    (((x) < (y)) ? (x) : (y))

int main() {
    freopen("palindrome.dat", "r", stdin);
    int N, i, len, slen; scanf("%d", &N);
    char S[MAXL], SS[MAXL];

    for (i = 0; i < N; i++) {
        scanf("%s", S);
        len = strlen(S);
        slen = len*2+3;
        
        int s, l, j;
        for (s = 0; s < slen; s++) 
            SS[s] = ((s-1) % 2 == 0) ? S[(s-1)/2] : M;
        
        printf("-- SS: %s\n", SS);
        int maxr = 0, maxi = 0, max = 0;
        int f[MAXL]; memset(f, 0, sizeof(f));
        for (s = 1; s < slen-1; s++) {
            if (maxr > s)
                f[s] = MIN(f[2*maxi-s], maxr-s);
            for (; SS[s+f[s]] == SS[s-f[s]]; f[s]++);
            if (f[s] + s > maxr) {
                maxr = f[s] + s;
                maxi = s;
            }
        }
        for (s = 0; s < slen; s++) {
            int d = 0;
            if (SS[s] == M) d = (f[s]-f[s]/2)*2;
            else            d = (f[s]/2)*2+1;
            max = (max > d) ? max : d;
        }
        printf("%d\n", max);
    }   
    return 0;
}
