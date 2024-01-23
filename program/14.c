#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/14.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    char word, tmp_char_num[10] = {'\0'};
    int word_num = 0, sum = 0, i = 8, mod_sum = 0;
    fscanf(fp, "%c", &word);
    printf("%c", word);
    // 英文代號先以下表轉換成數字
    if(word >= 'A' && word <= 'H'){
        word_num = word - 55;
    }else if(word >= 'J' && word <= 'N'){
        word_num = word - 56;
    }else if(word >= 'P' && word <= 'V'){
        word_num = word - 57;
    }else if(word >= 'X' && word <= 'Z'){
        word_num = word - 58;
    }else if (word == 'I'){
        word_num = 34;
    }else if(word == 'O'){
        word_num = 35;
    }else if(word == 'W'){
        word_num = 32;
    }
    // 各數字從右到左依次乘1,2,3,4,5,6,7,8
    while(fscanf(fp, "%c", &tmp_char_num[8 - i]) != EOF){
        printf("%c", tmp_char_num[8 - i]);
        sum += (tmp_char_num[8 - i] - '0') * i;
        i--;
    }
    sum += word_num % 10 * 9 + word_num / 10;
    // 計算上面兩項的總和，計算總和除10 後之餘數，再用10 減該餘數，結果就是檢查碼，若餘數為0，檢查碼就是 0
    mod_sum = sum % 10;
    // 輸出答案
    printf("\nAns=%c%s%d", word, tmp_char_num, 10 - mod_sum);   // 10 - mod_sum 是檢查碼
    return 0;
}