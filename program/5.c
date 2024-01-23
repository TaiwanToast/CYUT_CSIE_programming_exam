#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\5.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int nums[100] = {0}, index = 0, sum = 0, max = 0;
    char print_ch[200] = {'\0'};    //只是為了輸出題目的東西而已
    fgets(print_ch, 200, fp);       //以字串的方式讀入題目
    printf("%s\n", print_ch);   //輸出題目
    fseek(fp, 0, SEEK_SET);     //設定檔案指標到最開頭
    while(fscanf(fp, "%d", &nums[index]) != EOF){   //讀數字
        index++;
    }
    fclose(fp);
    //一個一個加，sum比max大，就把sum指派給max
    for (int i = 0; i < index; i++){
        sum = 0;    //重置sum
        for (int j = 0; j < index - 1; j++){
            sum += nums[i + j];
            if(max < sum){
                max = sum;
            }
        }
    }
    printf("Ans=%d", max);
    return 0;
}