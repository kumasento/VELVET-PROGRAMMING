#include <cstring>

int center_palin(char *palin) {
    int len = strlen(palin);
    int max = 0;
    for (int i = 0; i < len; i++) {
        int radius = (i < len-i-1) ? i : len-i-1;
        int t = 0;

        for (; t <= radius && palin[i+t] == palin[i-t]; t++);

        int palin_len = t * 2 - 1;
        max = (palin_len > max) ? palin_len : max;
    }

    return max;
}
