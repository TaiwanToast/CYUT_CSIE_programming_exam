#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\27.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    char q[101] = {'\0'}, tmp_ch = '\0', result = '\0';
    int c_flag = 0, n = 0;
    fgets(q, 100, fp);  // 為了印出題目，先整串讀進來
    printf("%s\nAns=", q);  // 印出題目
    fseek(fp, 0, SEEK_SET);     // 重設檔案指標回開頭
    while ((tmp_ch = fgetc(fp)) != EOF){
        if(tmp_ch == 'C'){      // 如果獨到C代表要讀偏移量了，所以將旗子立起，返回迴圈讀偏移量
            c_flag = 1;
            continue;
        }else if(c_flag){   // 旗子立起代表獨到偏移量了
            n = tmp_ch - '0';   // -'0'可以將字元數字轉換成數字
            c_flag = 0;     // 放下旗子
            continue;
        }else{  // 當沒有讀到C也沒有要讀偏移量，代表在讀資料
            result = tmp_ch - n;    // 往左偏移
            if(result < '0'){   // 如果偏移過多，就+10可以校正回歸
                result += 10;
            }
            printf("%c", result);   // 直接印出答案
        }
    }
    fclose(fp);

    return 0;
}