#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\26.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    // 讀檔
    int N = 0, nums[11] = {0};
    fscanf(fp, "%d", &N);
    printf("%d\n", N);
    for (int i = 0; i < N; i++){
        fscanf(fp, "%d", &nums[i]);
        printf("%d", nums[i]);      // 順便印出題目
        if(i < N - 1){
            printf(" ");
        }
    }
    fclose(fp);

    int max_num = 0, max_num_index = 0;
    // 最大值，最大值的索引
    for (int i = 0; i < N; i++){
        int count = 0, tmp_num_sum = 0, tmp_num = nums[i];
        // 計位數，數字的加總，佔存數字
        while(tmp_num > 0){     // 用此方法取得位數與數字加總
            tmp_num_sum += tmp_num % 10;
            tmp_num /= 10;
            count++;
        }
        int tmp = count * 10 + tmp_num_sum % 10;    // 依題目要求算法，算出新數值
        if(max_num < tmp){  // 如果當前最大值比剛算出的新數值小，那就重新指派新數值給最大值，並將最大值的索引更新成當前原數值的位置
            max_num = tmp;
            max_num_index = i;
        }
    }

    printf("\nAns=%d %d", max_num, nums[max_num_index]);    // 印出答案
    return 0;
}