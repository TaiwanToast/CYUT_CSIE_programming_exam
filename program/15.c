#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\15.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int n = 0, k = 0, count = 1;
    fscanf(fp, "%d %d", &n, &k);
    fclose(fp);
    for (int i = 10; i < n; i++){   //因為是數字總和，所以從10開始找即可
        int sum = 0, tmp_i = i;     //sum是數字總和，tmp_i是要被加總的數字
        while(tmp_i > 0){   //進行數字加總
            sum += tmp_i % 10;
            tmp_i /= 10;
        }
        if(sum == k){   //如果加總結果符合要求
            count++;    //計數器+1
        }
    }
    printf("%d %d\nAns=%d", n, k, count);   //印出答案
    return 0;
}