#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\11.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    char q[101] = {'\0'};
    fgets(q, 100, fp);
    printf("%s\n", q);
    fseek(fp, 0, SEEK_SET);
    int num[100] = {0};     //質數
    int num_remainder[100] = {0};       //餘數
    int index = 0;
    while(fscanf(fp, "%d", &num[index]) != EOF && fscanf(fp, "%d", &num_remainder[index]) != EOF){
        index++;
    }
    fclose(fp);
    //首先計算所有質數的乘積 N
    int N = 1;
    for (int i = 0; i < index; i++){
        N *= num[i];
    }
    //計算N 除以每個質數的商
    int quotient[100] = {0};    //商數
    for (int i = 0; i < index; i++){
        quotient[i] = N / num[i];
    }
    //計算這個商的倍數值，使得對原質數取餘數的結果為1
    int y[100] = {0};   //倍數值
    for (int i = 0; i < index; i++){
        int j = 1;
        while(1){
            if(quotient[i] * j % num[i] == 1){
                y[i] = j;
                break;
            }else{
                j++;
            }
        }
    }
    //答案x等於每個質數的商、倍數值、餘數三者乘積的總和mod 原來質數的乘積
    int x = 0;
    for (int i = 0; i < index; i++){
        x += quotient[i] * y[i] * num_remainder[i];
    }
    printf("Ans=%d", x % N);

    return 0;
}