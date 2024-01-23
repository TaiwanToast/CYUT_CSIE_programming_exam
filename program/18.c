//公式解
// #include <stdio.h>

// int is_leap_year(int year){     // 判斷閏年
//     return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);     // 西元年份除以4可整除，且除以100不可整除，又除以400可整除，為閏年
// }

// int cheak_date(int year, int month, int date){      // 檢查日期，如果非法就回傳1
//     if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31){    // 如果是大月，但日期大於31，即非法
//         return 1;
//     }else if(month == 2){
//         if(is_leap_year(year) && date > 29){    // 閏年二月要是29
//             return 1;
//         }else if(date > 28){    // 非閏年二月要是28
//             return 1;
//         }
//     }else if(date > 30){    // 其他就是小月，小月要是30日
//             return 1;
//     }
//     return 0;
// }

// int main(void){
//     FILE *fp;
//     fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\18.txt", "r");

//     if(fp == NULL){
//         printf("error open file.");
//         return 1;
//     }

//     int year = 0, month = 0, date = 0, week = 0;
//     char *ch_week[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  // 週幾

//     fscanf(fp, "%d %d %d", &year, &month, &date);
//     fclose(fp);

//     if(year < 1900 || year > 2100 || month < 1 || month > 12 || cheak_date(year, month, date)){     // 檢查日期
//         printf("Ans=Error");
//         return 1;
//     }
//     // 把一月和二月看做為上一年的十三和十四月，例:2001-1-10，換成2003-13-10來帶入公式計算
//     if(month == 1 || month == 2){
//         month = (month == 1 ? 13 : 14);
//         year -= 1;
//     }
//     //w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7
//     week = (date + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
//     printf("%d %d %d\nAns=%s", year, month, date, ch_week[week]);

//     return 0;
// }


// 將總日數 mod 7 的方法
#include <stdio.h>

int is_leap_year(int year){     // 判斷閏年
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);     // 西元年份除以4可整除，且除以100不可整除，又除以400可整除，為閏年
}

int cheak_date(int year, int month, int date){      // 檢查日期，如果非法就回傳1
    if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31){    // 如果是大月，但日期大於31，即非法
        return 1;
    }else if(month == 2){
        if(is_leap_year(year) && date > 29){    // 閏年二月要是29
            return 1;
        }else if(date > 28){    // 非閏年二月要是28
            return 1;
        }
    }else if(date > 30){    // 其他就是小月，小月要是30日
            return 1;
    }
    return 0;
}

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\18.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    int year = 0, month = 0, date = 0;
    fscanf(fp, "%d %d %d", &year, &month, &date);

    if(year < 1900 || year > 2100 || month < 1 || month > 12 || cheak_date(year, month, date)){     // 檢查日期
        printf("Ans=Error");
        return 1;
    }

    int days[] = {31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i = 0, total_days = 0;
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    for (i = 1900; i < year; i++){
        total_days += 365 + is_leap_year(i);
    }
    for (i = 1; i < month; i++){
        total_days += days[i - 1];
    }
    total_days += date;
    printf("%d %d %d\nAns=%s", year, month, date, week[total_days % 7]);
    return 0;
}