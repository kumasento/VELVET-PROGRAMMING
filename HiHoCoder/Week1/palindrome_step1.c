#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 1000010

int main() {
    freopen("palindrome.dat", "r", stdin);
    int N, i;
    char S[MAXL]; 

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s", S); 
        int s, l, j, len = strlen(S), max = 0;
        for (l = 1; l <= len; l++) 
            for (s = 0; s <= len-l; s++) {
                for (j = 0; j <= l-j-1; j++) 
                    if (S[s+j] != S[s+l-j-1])
                        break;
                if (l-j-1 <= j && max < l)
                    max = l;
            }
        printf("%d\n", max);
    }
}
