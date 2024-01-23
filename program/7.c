#include <stdio.h>
#include <stdlib.h>
void dec_to_bin(int num){
    int s = num, sy[100] = {0}, i = 0;
    //s為商，sy為餘數
    for (i = 0; s != 0; i++){
        sy[i] = s % 2; // 先將商數除2並取餘數，指派給餘數陣列
        s /= 2;        // 商數除2
    }
    //因為上述迴圈運算結果會與正解相反，所以要把運算結果倒反過來才是正解
    for (i = i - 1; i >= 0; i--){    //輸出正解
        printf("%d", sy[i]);
    }
    printf("+");
}
void base_dec_to_bin(double base){
    int result[3] = {0};
    for (int i = 0; i < 3; i++){
        base *= 2; // 小數*2
        if (base >= 1){                  // 如果乘出結果>=1
            result[i] = 1; // 將結果設為1
            base -= 1;     // 將大於1的部分減掉，使其變回小數
        }else{
            result[i] = 0; // 因為不>1，所以將結果設為0
        }
    }
    for (int i = 0; i < 3; i++){   //將答案的小數部分印出
        printf("%d", result[i]);
    }
}
int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/7.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    double BaseNum = 0.0;
    int num = 0;
    char q[101] = {'\0'};   //只為輸出題目
    fgets(q, 100, fp);  //以字串的方式讀入題目
    printf("%s\nAns=", q);  //印出題目
    fseek(fp, 0, SEEK_SET);     //重新設定檔案指標，設定到檔案最開頭
    fscanf(fp, "%lf", &BaseNum);    //以小數的方式讀入題目
    num = (int)BaseNum;     //整數部分 = 強制型態轉變的浮點數
    BaseNum = BaseNum - num;    //小數部分 = 題目數字 - 整數

    dec_to_bin(num);            // 十進制轉二進制函式，傳入十進制數字
    base_dec_to_bin(BaseNum);  //小數十進制轉二進制函式，傳入十進制小數
    return 0;
}