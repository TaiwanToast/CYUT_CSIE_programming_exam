#include <stdio.h>
#include <string.h>     //C語言標準函式庫中自帶的函式，專門處理字串

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\2.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    char str[201] = {'\0'};     //題目說不超過200個字元，所以宣告201個字元的陣列
    fgets(str, 201, fp);    //利用此函式能夠直接讀入設定多少個字元的字串
    fclose(fp);     //關檔
    printf("%s\n", str);    //直接印出題目要求的原字串
    int len_ = strlen(str), L_flag = 0, L_index = 0;
    //宣告len_為字串長度，找到L時就立起來的旗子，當找到L時將L的位置存起來的變數
    //strlen(字串) 此函示可以抓到字串長度
    for (int i = len_; i >= 0; i--){    //從字串末端開始找
        if(str[i] == 'a' || str[i] == 'A'){     //當遇到A
            for (int j = i; j < len_; j++){     //往回找L
                if(str[j] == 'l' || str[j] == 'L'){     //有找到L
                    L_flag = 1;     //旗子立起來
                    L_index = j;    //L的位置記下
                    break;      //直接跳脫找L的迴圈
                }
            }
            if(L_flag){     //如果有找到L
                for (int j = i; j <= L_index; j++){
                    str[j] = '%';   //將AL字串改成%
                }
                L_flag = 0;     //將旗子放下
            }
        }
    }
    //輸出答案
    printf("Ans=");
    for (int i = 0; i < len_; i++){
        if(str[i] != '%'){      //將不是%的字元輸出出來就好了
            printf("%c", str[i]);
        }
    }
    return 0;
}