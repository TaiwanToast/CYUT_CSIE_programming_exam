#include <stdio.h>

int check_month(int month){     //檢查大小月
    if(month == 2){     //2月個別判斷
        return 28;
    }
    if(month < 8){      //如果比8月小，那奇數月就是大月
        if(month % 2 != 0){
            return 31;
        }else{
            return 30;
        }
    }else{      //否則比8越大，偶數月就是大月
        if(month % 2 == 0){
            return 31;
        }else{
            return 30;
        }
    }
}

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/13.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int input_month = 0, input_day = 0, total_day = 0;
    fscanf(fp, "%d %d", &input_month, &input_day);
    fclose(fp);
    //以上讀檔
    printf("%d %d\n", input_month, input_day);
    for (int i = 1; i < input_month; i++){      //將所有月份的日數加起來
        total_day += check_month(i);
    }
    printf("Ans=%d", ((total_day + input_day) % 7) + 1);    //最後再加當月的日，mod 7 + 1，即是答案
    return 0;
}