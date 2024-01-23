#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\17.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int nums[100] = {0}, index = 0;
    // 直接讀入全部數字
    while(fscanf(fp, "%d", &nums[index]) != EOF){
        index++;
    }
    fclose(fp);

    int K = nums[index - 1];    // 最後一個數字一定是K
    index--;    // 因為最後一個數字是K，所以索引要減1
    int result[100] = {0}, result_index = 0;    // 宣告答案陣列和答案陣列的索引
    for (int i = K - 1; i < index; i++){
        int tmp_nums[100] = {0}, j_index = 0;   // 暫存欲慮波的數字
        for (int j = i; j >= i - (K - 1); j--){ // 將欲慮波的數字提出
            tmp_nums[j_index] = nums[j];
            j_index++;
        }
        // 利用氣泡排序法排序
        for (int j = 0; j < j_index - 1; j++){
            for (int k = j + 1; k < j_index; k++){
                if(tmp_nums[j] > tmp_nums[k]){
                    int tmp = tmp_nums[j];
                    tmp_nums[j] = tmp_nums[k];
                    tmp_nums[k] = tmp;
                }
            }
        }
        // 將中間值提出，並存入答案陣列中
        result[result_index] = tmp_nums[K / 2];
        result_index++;
    }
    // 印出題目及答案
    for (int i = 0; i < index; i++){
        printf("%d", nums[i]);
        if(i < index - 1){
            printf(" ");
        }
    }
    printf("\n%d\nAns=", K);
    for (int i = 0; i < result_index; i++){
        printf("%d", result[i]);
        if (i < result_index - 1){
            printf(" ");
        }
    }

    return 0;
}