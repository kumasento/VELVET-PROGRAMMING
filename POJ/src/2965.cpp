#include <iostream>
#include <cstdio>

#define LEN 4
#define OPEN 1
#define CLOSE 0
#define MAXLEN 100

using namespace std;

void print_mat(int mat[LEN][LEN]) {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++)
            printf("%d ", mat[i][j]);
        puts("");
    }
}
void copy(int mat[LEN][LEN], int cp_mat[LEN][LEN]) {
    for (int i = 0; i < LEN; i++)
        for (int j = 0; j < LEN; j++)
            cp_mat[i][j] = mat[i][j];
}

int i_seq[MAXLEN], j_seq[MAXLEN];
int counter = 0;

void flip(int mat[LEN][LEN], int i, int j) {
    mat[i][j] = (mat[i][j]+1) % 2;
    for (int t = 0; t < LEN; t++) mat[i][t] = (mat[i][t]+1) % 2;
    for (int t = 0; t < LEN; t++) mat[t][j] = (mat[t][j]+1) % 2;

    i_seq[counter] = i;
    j_seq[counter] = j;
    counter ++;
}

int main() {
    freopen("../data/2965.txt", "r", stdin);
    
    int mat[LEN][LEN];
    int cp_mat[LEN][LEN];
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            char ch; scanf("%c", &ch);
            if (ch == '-') mat[i][j] = OPEN;
            if (ch == '+') mat[i][j] = CLOSE;
        }
        getchar();
    }
    copy(mat, cp_mat);
    //print_mat(mat);

    const int MAX_ITER = 1<<(LEN*LEN);
    const int MIN = 1000;
    int min_res = MIN;
    int min_i_seq[MAXLEN], min_j_seq[MAXLEN];

    for (int iter = 0; iter < MAX_ITER; iter ++) {
        counter = 0;
        for (int idx = 0; idx < LEN*LEN; idx ++) {
            int is_flip = 1 & (iter>>idx);
            if (is_flip) {
                int x = idx / LEN;
                int y = idx % LEN;
                flip(mat, x, y);
            }
        }

        bool ok = true;
        for (int i = 0; i < LEN; i++)
            for (int j = 0; j < LEN; j++)
                if (mat[i][j] != OPEN) {
                    ok = false;
                    break;
                }

        if (ok && counter < min_res) {
            min_res = counter;
            for (int i = 0; i < min_res; i++) {
                min_i_seq[i] = i_seq[i];
                min_j_seq[i] = j_seq[i];
            }
        }
        
        copy(cp_mat, mat);
    }

    printf("%d\n", min_res);
    for (int i = 0; i < min_res; i++)
        printf("%d %d\n", min_i_seq[i]+1, min_j_seq[i]+1);

    /*
    puts("check correctness:");
    print_mat(mat);
    for (int i = 0; i < min_res; i++) {
        flip(mat, min_i_seq[i], min_j_seq[i]);
        print_mat(mat);
        puts("");
    }
    */
    return 0;
}
