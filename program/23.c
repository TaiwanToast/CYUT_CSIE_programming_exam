#include <stdio.h>

int is_odd_number(int num){     // 用於判斷是否為質數的函數
    for (int i = 2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\23.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int n = 0;
    fscanf(fp, "%d", &n);
    fclose(fp);

    int denominator[100] = {0}, numerator[100] = {0}, index = 0; // denominator分母，numerator分子
    // 先找分子再找分母
    for (int i = 3; index < n; i++){    // 因為是大於二的質數，所以從3開始
        if(is_odd_number(i)){       // 如果是質數
            numerator[index] = i;   // 存起來
        }else{      // 不是的話，直接continue
            continue;
        }
        // 沒有continue才會到以下判斷式，找分母
        // 最接近分子又能被4整除，那就只有+-1而已，所以考慮-1及+1即可
        if((i - 1) % 4 != 0){   // 如果-1能被4整除，即是分母
            denominator[index] = i - 1;
            index++;
        }else{  // 否則一定是+1的那個
            denominator[index] = i + 1;
            index++;
        }
    }
    
    // 印出題目與答案
    printf("%d\nAns=", n);
    for (int i = 0; i < index; i++){
        printf("%d", numerator[i]);
        if(i < index - 1){
            printf("*");
        }
    }
    printf("\nAns=");
    for (int i = 0; i < index; i++){
        printf("%d", denominator[i]);
        if(i < index - 1){
            printf("*");
        }
    }
    return 0;
}