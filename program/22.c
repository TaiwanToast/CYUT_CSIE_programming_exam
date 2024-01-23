#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\22.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int N = 0, nums[100] = {0}, index = 0;
    fscanf(fp, "%d", &N);
    while (fscanf(fp, "%d", &nums[index]) != EOF){
        index++;
    }
    fclose(fp);

    // 印出題目
    printf("%d\n", N);
    for (int i = 0; i < index; i++){
        printf("%d", nums[i]);
        if(i < index - 1){
            printf(" ");
        }
    }
    
    // 氣泡排序
    if(N == 0){     // 0代表輸出結果由小至大排列
        for (int i = 0; i < index; i++){
            for (int j = 0; j < i; j++){
                if(nums[i] < nums[j]){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }else{      // 否則反之
        for (int i = 0; i < index; i++){
            for (int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
    }

    printf("\nAns=");
    for (int i = 0; i < index; i++){
        printf("%d", nums[i]);
        if(i < index - 1){
            printf(" ");
        }
    }

    return 0;
}