#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\20.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int N = 0, M = 0, K = 0;
    fscanf(fp, "%d %d %d", &N, &M, &K);
    fclose(fp);

    int x1 = 1, x2 = 2, x3 = 3, index = 0, flag = 0;

    for (int i = 4; i <= N; i++){
        int xi = (x1 + x2 + x3) % M + 1;    // 依題目要求計算
        if(xi == K){    // 如果有計算結果與題目要求一致
            flag = 1;   // 將旗子立起來
            index = i;  // 將位置記起來
            break;      // 找到就可以跳脫迴圈了
        }
        // 沒找到的話，將數列後移
        x1 = x2;
        x2 = x3;
        x3 = xi;
    }
    // 如果有找到，印出位置，否則印出No
    flag ? printf("%d %d %d\nAns=%d", N, M, K, index) : printf("%d %d %d\nAns=No", N, M, K);

    return 0;
}