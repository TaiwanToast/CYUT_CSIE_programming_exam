#include <stdio.h>
#include <math.h>

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/3.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    double nums[100] = {0.0};   //存數字的地方
    char symbols[100] = {'\0'}, p[200] = {'\0'};    //symbols是存運算符號的地方，p只是為了輸出題目而有的
    int index = 0;      //索引
    fgets(p, 200, fp);      //先讀入題目的字串並輸出，就沒用處了
    printf("%s", p);
    fseek(fp, 0, SEEK_SET);     //將檔案指標只回檔案開頭
    while(fscanf(fp, "%lf", &nums[index]) != EOF && fscanf(fp, "%c", &symbols[index]) != '='){      //只要不讀到檔案結尾，以及不讀到'='，就繼續讀下去
        index++;
    }
    fclose(fp);
    double tmp = nums[0];   //宣告暫存以便運算
    //以下開始依照算式運算
    for (int i = 0; i < index; i++){
        if(symbols[i] == '+'){
            tmp += nums[i + 1];
        }else if(symbols[i] == '-'){
            tmp -= nums[i + 1];
        }else if(symbols[i] == '*'){
            tmp *= nums[i + 1];
        }else if(symbols[i] == '/'){
            tmp /= nums[i + 1];
        }
    }
    int result = round(tmp);    //宣告結果為tmp的四捨五入
    printf("%d", result);   //輸出結果
    return 0;
}