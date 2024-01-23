#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\31.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    char str[100][100] = {'\0'}, tmp_ch = '\0';
    int row_index = 0, col_index = 0, tmp_len = 0, max_len = 0;
    while((tmp_ch = fgetc(fp)) != EOF){
        if(tmp_ch != ' '){      // 不是空格代表是字元
            str[row_index][col_index] = tmp_ch;     // 讀入陣列中
            col_index++;    // 行索引+1
            tmp_len++;      // 字串長度+1
        }else{  // 是空格的化
            tmp_len = 0;    // 歸零長度
            col_index = 0;  // 歸零行索引
            row_index++;    // 列索引+1
        }
        if(max_len < tmp_len){  // 如果最長長度比當前長度小，那就指派當前最長長度給max_len
            max_len = tmp_len;
        }
    }
    fclose(fp);
    
    // 先印出題目
    for (int i = 0; i <= row_index; i++){
        printf("%s", str[i]);
        if(i < row_index){
            printf(" ");
        }
    }
    printf("\n");

    // 印出第一行的*
    for (int i = 0; i < max_len + 2; i++){
        printf("*");
    }
    printf("\n");   // 換行開始印字元部分

    for (int i = 0; i <= row_index; i++){
        printf("*");    // 頭一個一定是*
        for (int j = 0; j < max_len; j++){
            if(str[i][j] != '\0'){      // 不是'\0'就是字元，是字元就印出
                printf("%c", str[i][j]);
            }else{  // 不是字元就印出空格
                printf(" ");
            }
        }
        printf("*\n");  // 印出最後的*，並換行
    }

    // 印出最後一行*
    for (int i = 0; i < max_len + 2; i++){  
        printf("*");
    }

    return 0;
}