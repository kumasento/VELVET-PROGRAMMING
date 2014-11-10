#include <cstdio>
#include <iostream>

#define LEN 4

using namespace std;

int counter = 0;

inline void print_board(int mat[LEN][LEN]) {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
}

inline void flip_board(int mat[LEN][LEN], int i, int j) {
    mat[i][j] = (mat[i][j]+1) % 2;
    if (i+1 < LEN) mat[i+1][j] = (mat[i+1][j]+1) % 2;
    if (j+1 < LEN) mat[i][j+1] = (mat[i][j+1]+1) % 2;
    if (i-1 >= 0) mat[i-1][j] = (mat[i-1][j]+1) % 2;
    if (j-1 >= 0) mat[i][j-1] = (mat[i][j-1]+1) % 2;
    counter ++;
}

int main() {
    freopen("../data/1753.txt", "r", stdin);
    
    int mat[LEN][LEN];
    for (int i = 0; i < LEN; i++){
        for (int j = 0; j < LEN; j++) {
            char ch; scanf("%c", &ch);
            if (ch == 'b') mat[i][j] = 0;
            else if (ch == 'w') mat[i][j] = 1;
        }
        getchar();
    }
    int cp_mat[LEN][LEN];
    for (int i = 0; i < LEN; i++)
        for (int j = 0; j < LEN; j ++)
            cp_mat[i][j] = mat[i][j];
    //print_board(mat);
    
    int min_result = 1000;
    for (int color = 0; color <= 1; color ++) {
        int MAXITER = 16;
        for (int iter = 0; iter < MAXITER; iter ++) {
            counter = 0;
            //printf(">>color=%d iter=%d\n", color, iter);

            for (int idx = 0; idx < LEN; idx ++) {
                int is_flip = 1 & (iter>>idx);
                if (is_flip)
                    flip_board(mat, 0, idx);
            }

            for (int x = 1; x < LEN; x++) 
                for (int y = 0; y < LEN; y++) 
                    if (mat[x-1][y] != color) 
                        flip_board(mat, x, y);

            bool ok = true;
            for (int y = 0; y < LEN && ok; y++)
                ok = (mat[LEN-1][y] == color);

            if (ok && counter < min_result)
                min_result = counter;

            for (int i = 0; i < LEN; i++)
                for (int j = 0; j < LEN; j ++)
                    mat[i][j] = cp_mat[i][j];
        }
    }
    
    if (min_result == 1000) 
        puts("Impossible");
    else
        printf("%d\n", min_result);

    return 0;
}
