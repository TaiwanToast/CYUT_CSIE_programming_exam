#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\30.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int n = 0;
    fscanf(fp, "%d", &n);
    printf("%d\n", n);
    int valid_flag[100] = {0};
    fseek(fp, 2, SEEK_CUR);     // 偏移2才可以讀到數字
    for (int i = 0; i < n; i++){    // n筆資料，讀n次
        char tmp_ch;
        int nums[100] = {0}, index = 0;
        while ((tmp_ch = fgetc(fp)) != EOF && tmp_ch != '\n'){  // 只要還沒讀到檔案結尾，也還沒讀到換行符號就繼續讀
            if(tmp_ch >= '0' && tmp_ch <= '9'){
                nums[index] = tmp_ch - '0';     // 轉換成數字
                index++;
            }
        }

        for (int j = 0; j < index; j++){    // 先印出題目
            printf("%d", nums[j]);
            if(j < index - 1) printf(" ");
        }
        printf("\n");

        for (int j = 0; j < index; j += 2){     // 反轉後偶數位*2，其實就是沒反轉奇數位*2
            nums[j] *= 2;
        }

        FILE *TmpFp;
        TmpFp = tmpfile();  // 建立一個佔存檔案
        for (int j = 0; j < index; j++){    // 把*2好的數字全部丟進去
            fprintf(TmpFp, "%d", nums[j]);
        }
        fseek(TmpFp, 0, SEEK_SET);  // 重設檔案指標
        int sum = 0;
        char ch_num;
        while((ch_num = fgetc(TmpFp)) != EOF){  // 在以字元形態一個一個讀進
            sum += ch_num - '0';    // 轉換成數字後加總
        }
        fclose(TmpFp);  // 記得關檔
        if(sum % 10 == 0) valid_flag[i] = 1;    // 如果加總結果是10的倍數，代表有效，那就把旗子立起來
    }
    fclose(fp);     // 關檔
    // 印出答案
    printf("Ans=");
    for (int i = 0; i < n; i++){
        valid_flag[i] ? printf("valid") : printf("invalid");
        if(i < n - 1) printf(" ");
    }

    return 0;
}