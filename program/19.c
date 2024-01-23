#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\19.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    char part_str[100] = {'\0'}, data_str[100] = {'\0'}, tmp_ch = '\0';
    int part_str_index = 0, data_str_index = 0, part_end_flag = 0;

    while((tmp_ch = fgetc(fp)) != EOF){
        printf("%c", tmp_ch);       // 順便印出題目
        if(tmp_ch == ' '){      // 遇到空格代表要讀資料字串了
            part_end_flag = 1;  // 立起旗子
            continue;
        }
        if(!part_end_flag){     // 旗子還沒立起來，代表還沒讀完部分字串
            part_str[part_str_index] = tmp_ch;
            part_str_index++;
        }else{
            data_str[data_str_index] = tmp_ch;
            data_str_index++;
        }
    }
    fclose(fp);

    int j = 0, count = 0;
    // 依序往後找，以範例輸入一為例，b在2，再繼續從b的位置2繼續往下找，以此類推
    // 找到，計數器加一
    for (int i = 0; i < part_str_index; i++){
        for (j = j; j < data_str_index; j++){
            if(data_str[j] == part_str[i]){
                count++;
                break;
            }
        }
    }
    count == part_str_index ? printf("\nAns=Yes %s", data_str) : printf("\nAns=No %s", data_str);   // 如果計數器的數值與部分字串的字元數一致，代表都有找到，則輸出yes，反之則No
    return 0;
}