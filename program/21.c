#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\21.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    char ch_num1[11] = {'\0'}, ch_num2[11] = {'\0'}, tmp_ch = '\0';
    int index = 0, flag = 0;
    while ((tmp_ch = fgetc(fp)) != EOF){
        if(tmp_ch == '\n'){     // 如果讀到換行字元就代表要讀第二個字串
            flag = 1;   // 立起旗子代表要讀第二個字串
            index = 0;  // 索引歸0
            continue;
        }

        if(!flag){
            ch_num1[index] = tmp_ch;
        }else{
            ch_num2[index] = tmp_ch;
        }

        index++;
    }
    fclose(fp);

    int A_count = 0, B_count = 0;
    for (int i = 0; i < index; i++){
        for (int j = 0; j < index; j++){
            if(i == j){     // 當在同一個位置，數字相同
                if(ch_num1[i] == ch_num2[j]){
                    A_count++;  // A計數器就+1
                }
            }else if(ch_num1[i] == ch_num2[j]){     // 不在相同位置，但數字相同
                B_count++;  // B計數器+1
            }
        }
    }

    printf("%s\n%s\nAns=%dA%dB", ch_num1, ch_num2, A_count, B_count);   // 印出題目及答案
    return 0;
}