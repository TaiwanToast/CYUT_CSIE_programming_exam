#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\28.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int n = 0;
    fscanf(fp, "%d", &n);
    fseek(fp, 2, SEEK_CUR);
    int sum[100] = {0};
    // 直接邊讀檔邊解
    for (int i = 0; i < n; i++){
        char ch_points[100] = {'\0'}, tmp_opint = '\0';
        int points_index = 0;
        // 讀入資料
        while((tmp_opint = fgetc(fp)) != EOF && tmp_opint != '\n'){
            printf("%c", tmp_opint);    // 順便印出題目
            if(tmp_opint != ' '){   // 過濾掉空格
                ch_points[points_index] = tmp_opint;
                points_index++;
            }
        }
        printf("\n");
        // 先將x和/的分數算出來，其他數字就直接轉成數字
        int num_points[100] = {0}, break_flag = 0;
        for (int j = points_index - 1; j >= 0; j--){
            if(ch_points[j] != 'X' && ch_points[j] != '/'){     // 不是x和/就一定是數字，轉換成數字後存起來
                num_points[j] = ch_points[j] - '0';
            }else if(ch_points[j] == '/'){      // 是/的話
                if(ch_points[j + 1] == '\0' || j - 1 == -1){    // 先看能不能算得出來，不能就直接跳脫迴圈
                    break_flag = 1;
                    break;
                }
                num_points[j] = 10 - (ch_points[j - 1] - '0') + (ch_points[j + 1] - '0');   // 依題目要求算法算
            }else if (ch_points[j] == 'X'){     // 是X的話
                if(ch_points[j + 1] == '\0' || ch_points[j + 2] == '\0'){   // 先看能不能算得出來，不能就直接跳脫迴圈
                    break_flag = 1;
                    break;
                }
                // 如果後面連續兩個數中有大於10的，就已10計算
                if(num_points[j + 1] > 10 && num_points[j + 2] <= 10){
                    num_points[j] = 20 + num_points[j + 2];
                }else if(num_points[j + 1] <= 10 && num_points[j + 2] > 10){
                    num_points[j] = 20 + num_points[j + 1];
                }else if(num_points[j + 1] > 10 && num_points[j + 2] > 10){
                    num_points[j] = 30;
                }else{
                    num_points[j] = 10 + num_points[j + 1] + num_points[j + 2];
                }
            }
        }
        if(!break_flag){    // 只要沒被跳脫迴圈就代表算得出來，就可以加總
            for (int j = 0; j < points_index; j++){
                sum[i] += num_points[j];
            }
        }else{      // 否則以-1標記不能加總
            sum[i] = -1;
        }
    }
    fclose(fp);
    // 印出答案
    printf("Ans=");
    for (int i = 0; i < n; i++){
        sum[i] == -1 ? printf("Unknown") : printf("%d", sum[i]);    // 如果被-1標記，就印出Unknown，否則印出加總
        if(i < n - 1){
            printf(" ");
        }
    }

        return 0;
}