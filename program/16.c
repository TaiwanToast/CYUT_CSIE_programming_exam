#include <stdio.h>
#include <math.h>
int main(){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\16.txt", "r");
    if(fp == NULL){
        printf("error");
        return 1;
    }
    int money = 0, year = 0, total_money = 0;
    fscanf(fp, "%d%d%d", &money, &year, &total_money);  //依序讀入本金、年數和本利和
    fclose(fp);
    double result = 0.01/100;   //宣告復利率，因為是百分比，所以除100
    while(1){
        double tmp_total = money;   //宣告暫存本利和的變數
        int i = 0;
        // 計算本利和
        for(i=0; i < year - 1; i++){
           tmp_total = tmp_total * (1 + result) + money;
           tmp_total = lround(tmp_total);
        }
        tmp_total *= (1 + result);
        int total = round(tmp_total);   //記得四捨五入

        // 如果計算出的本利和與題目要求相同，就可以跳出迴圈輸出答案
        if(total == total_money){
            break;
        }else{
            result += 0.01 / 100;
        }
    }
    printf("%d\n%d\n%d\nAns=%.2lf%%", money, year, total_money, result * 100);
    return 0;
}
// 一個一個慢慢算