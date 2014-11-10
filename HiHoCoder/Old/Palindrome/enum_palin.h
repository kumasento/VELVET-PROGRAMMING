
#include <cstring>

int enum_palin(char *origin_string) {
    int len = strlen(origin_string);
    int max = 0;
    for (int i = 0; i < len; i++) 
        for (int j = i+1; j <= len; j++) { 
            bool is_palin = true;
            for (int k = i; k < j && is_palin; k++) 
                if (origin_string[k] != origin_string[j-(k-i)-1])
                    is_palin = false;
            if (is_palin && j-i > max)
                max = j-i;
        }

    return max;
}
