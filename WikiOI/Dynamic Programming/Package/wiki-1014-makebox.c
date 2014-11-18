#include <stdio.h>
#include <stdlib.h>

#define ITEM_NUM 100
#define MAX_SIZE 20010

int main() {
    freopen("1014.txt", "r", stdin);
    int V, N, C[ITEM_NUM], i, v;
    int F[ITEM_NUM][MAX_SIZE];

    scanf("%d", &V);
    scanf("%d", &N);
    for (i = 1; i <= N; i++) 
        scanf("%d", &C[i]);
    
    for (v = 0; v < MAX_SIZE; v++)
        F[0][v] = 0;
    for (i = 1; i <= N; i++) {
        for (v = 0; v < C[i]; v++)
            F[i][v] = F[i-1][v];
        for (v = C[i]; v <= V; v++) {
            int noput = F[i-1][v];
            int input = F[i-1][v-C[i]] + C[i];
            //printf("%d %d %d %d\n", i, v, noput, input);
            F[i][v] = (noput < input) ? input : noput;
        }
    }
    
    printf("%d\n", V-F[N][V]);

    return 0;
}
