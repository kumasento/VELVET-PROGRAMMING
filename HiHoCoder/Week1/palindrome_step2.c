#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1000010
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main() {
    freopen("palindrome.dat", "r", stdin);
    int N, i; scanf("%d", &N);
    char S[MAXL];
    for (i = 0; i < N; i++) {
        scanf("%s", S); printf("-- Case #%d: %s\n", i, S);
        int len = strlen(S), s, max = 0, d, l;
        int slen = len * 2 - 1;
        // ['a','b','b','a'] -> ['a','#','b','#','b','#','a']
        // s = 1; slen-s-1 = 5
        for (s = 0; s < slen; s++) {
            int rs = s/2;
            for (l = 0; l <= MIN(s, slen-s-1); l++)
                if (S[rs-l] != S[rs+l])
                    break;
            if (S[s-l] != S[s+l]) l --;
            int k;
            for (k = s-l; k <= s+l; k++) 
                printf("%c", S[k]);
            printf("\n");
            if (S[s] == '#') d = (l-l/2) * 2;
            else             d = (l/2) * 2 + 1;
            if (d > max) max = d;
        }
        printf("%d\n", max);
    }

    return 0;
}
