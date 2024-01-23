#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/12.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int N = 0;  //摺疊長度
    fseek(fp, -1, SEEK_END);    //設定檔案字元指標的位置，設定到檔案結尾的前一個
    fscanf(fp, "%d", &N);   //讀入摺疊長度
    FILE *fp2;
    fp2 = tmpfile();    //建立一個暫存的檔案
    char tmp_q;     //暫存讀入的字元
    int count = 0;  //計數器，計算有沒有達到摺疊長度用
    fseek(fp, 0, SEEK_SET);     //重新設定檔案字元指標的位置，設定到檔案開頭
    while(1){   //開始讀入
        tmp_q = fgetc(fp);
        printf("%c", tmp_q);    //順便把題目印出
        if(tmp_q == '\n'){  //如果是換行字元就中斷，因為第二行是摺疊長度
            break;
        }
        fprintf(fp2, "%c", tmp_q);  //把題目印到暫存檔案中
        count++;
        if(count == N){     //如果達到摺疊長度，就在暫存檔案中印出空格
            fprintf(fp2, " ");
            count = 0;
        }
    }
    int num = 0, sum = 0;
    fseek(fp2, 0, SEEK_SET);    //重新設定檔案字元指標的位置，設定到檔案開頭
    while(fscanf(fp2, "%d", &num) != EOF){      //讀入數字並加總
        sum += num;
    }
    printf("Ans=%d", sum);      //加總結果即是答案
    fclose(fp);
    fclose(fp2);
    return 0;
}