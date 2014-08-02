#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
    freopen("poj_3167.in", "r", stdin);
    int N, K, S; scanf("%d%d%d", &N, &K, &S);
        
    int spots[N], ptrn[N];
    for (int i = 0; i < N; i++) scanf("%d", &spots[i]);
    for (int i = 0; i < K; i++) scanf("%d", &ptrn[i]);
    

    return 0;
}
