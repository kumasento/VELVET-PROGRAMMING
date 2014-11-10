#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1000010
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main() {
    freopen("palindrome.dat", "r", stdin);
    int N, i; scanf("%d", &N);
    char S[MAXL], SS[MAXL];
    for (i = 0; i < N; i++) {
        scanf("%s", S); 
        int len = strlen(S), s, max = 0, d, l;
        int slen = len * 2 - 1;
        for (s = 0; s < slen; s++)
            SS[s] = (s % 2 == 0) ? S[s/2] : '#'; 

        // ['a','b','b','a'] -> ['a','#','b','#','b','#','a']
        // s = 1; slen-s-1 = 5
        for (s = 0; s < slen; s++) {
            for (l = 0; l <= MIN(s, slen-s-1); l++)
                if (SS[s-l] != SS[s+l])
                    break;
            if (SS[s-l] != SS[s+l]) l --;
            
            if (SS[s] == '#')   d = (l-l/2) * 2;
            else                d = (l/2) * 2 + 1;
            
            if (d > max) max = d;
        }
        printf("%d\n", max);
    }

    return 0;
}
