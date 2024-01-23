#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\33.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int n = 0;
    fscanf(fp, "%d", &n);
    int nums[100] = {0}, index = 0;
    while(fscanf(fp, "%d", &nums[index]) != EOF){
        index++;
    }
    fclose(fp);
    // 先印出題目
    printf("%d\n", n);
    for (int i = 0; i < index; i++){
        printf("%d", nums[i]);
        if(i < index - 1){
            printf(" ");
        }
    }

        int count = 0;
    // 翻開後是一對的話，就改成-1標示有找到配對
    for (int i = 0; i < index; i++){
        if(nums[i] != -1){  // 如果沒被配對過
            count++;    // 先翻開i
            for (int j = i + 1; j < index; j++){
                count++;    // 翻開j
                if (nums[i] == nums[j]){    // 翻開發現是一對
                    nums[i] = -1;   // 改成-1標示配對過
                    nums[j] = -1;
                    break;
                }
                else{
                    count++;     // 否則就直接+1，並往下找
                }
            }
        }
    }
    // 印出答案
    printf("\nAns=%d", count);
    return 0;
}