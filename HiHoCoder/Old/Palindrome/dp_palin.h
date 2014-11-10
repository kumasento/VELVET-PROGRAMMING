#include <cstdlib>
#include <cstring>

int dp_palin(char *palin) {
    int len = strlen(palin);

    int dp[len+1][len+1];
    int maxlen = 0;
    for (int l = 1; l <= len; l++) {
        for (int idx = 0; idx < len; idx ++) {            
            int i = idx;
            int j = idx + l - 1;
            // find if 'inner palin' exists
            if (i+1 <= j-1) dp[i][j] = (dp[i+1][j-1] && palin[i] == palin[j]) ? 1 : 0;
            else dp[i][j] = (palin[i] == palin[j]) ? 1 : 0;

            if (dp[i][j] && maxlen < l) maxlen = l;
        }
    }

    return maxlen;
}
