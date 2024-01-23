#include<stdio.h>

int main() {
    int mat[500][10000] = {0};
    int tmp = 1;
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            mat[i][j] = tmp++;
            printf("[%d] ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}