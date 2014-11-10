#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 1000010
#define MAXL 10010

using namespace std;

void getNext(int *NEXT, int str_len, char *ptrn) {
    NEXT[0] = -1;
    for (int i = 1; i <= str_len; i++) {
        int q = i-1;
        while (NEXT[q] != -1) {
            if (ptrn[i-1] == ptrn[NEXT[q]])
                break;
            q = NEXT[q];
        }
        NEXT[i] = NEXT[q]+1;
    }
}

int cntMatch(char *orgn, char *ptrn, int orgn_len, int ptrn_len, int *NEXT) {
    int p = 1, q = 1;
    int cnt = 0;
    while (p + q - 1 <= orgn_len) {
        if (orgn[p+q-2] == ptrn[q-1])
            if (q == ptrn_len) {
                cnt ++;
                if (NEXT[q] != 0)
                    q = NEXT[q], p = p - NEXT[q] + 1;
                else 
                    q = 1, p++;
            }
            else
                q++;
        else 
            if (NEXT[q] != 0)
                q = NEXT[q], p = p - NEXT[q] + 1;
            else 
                q = 1, p++;
    }
    return cnt;
}

int main(){
    freopen("w3.in", "r", stdin);
    int T; cin>>T;
    while (T--) {
        char orgn[MAXN], ptrn[MAXL];
        scanf("%s%s", ptrn, orgn);
        //printf("%s %s\n", ptrn, orgn);

        int ptrn_len = strlen(ptrn);
        int orgn_len = strlen(orgn);
        if(ptrn_len > orgn_len) {
            printf("0\n");
            continue;
        }
        int NEXT[ptrn_len+1];
        getNext(NEXT, ptrn_len, ptrn);
        printf("%d\n",cntMatch(orgn, ptrn, orgn_len, ptrn_len, NEXT));
    }

    return 0;
}
