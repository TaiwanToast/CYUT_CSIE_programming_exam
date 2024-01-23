#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/8.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int x[3] = {0}, B[3] = {-16, 45, -18}, A[3][3] = {{4, 1, 3}, {2, 9, 5}, {1, 2, 9}}, a = 36;
    fscanf(fp, "%d %d %d", &x[0], &x[1], &x[2]);
    fclose(fp);
    int result = (x[0] * x[0] * A[0][0]     //展開公式後的算式
                + x[0] * x[1] * A[1][0]
                + x[0] * x[2] * A[2][0]
                + x[0] * x[1] * A[0][1]
                + x[1] * x[1] * A[1][1]
                + x[2] * x[1] * A[2][1]
                + x[0] * x[2] * A[0][2]
                + x[1] * x[2] * A[1][2]
                + x[2] * x[2] * A[2][2])
                + (x[0] * B[0] + x[1] * B[1] + x[2] * B[2])+ a;
    printf("%d %d %d\nAns=%d", x[0], x[1], x[2], result);

    return 0;
}