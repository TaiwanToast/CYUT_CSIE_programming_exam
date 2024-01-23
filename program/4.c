// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     FILE *fp;
//     fp = fopen("D:/.Vscode/C/porgram_C/txt/4.txt", "r");
//     if(fp == NULL){
//         printf("error");
//         return 0;
//     }
//     char ch[100] = {'\0'}, Tmp_ch;
//     int index = 0, i = 0, j = 0, num[100] = {0}, Tmp_num = 0, result = 0;
//     while((Tmp_ch = getc(fp)) != EOF){  //讀檔
//         ch[index] = Tmp_ch;
//         index++;    //總字數
// 	}
//     fclose(fp); //關檔
//     for(i = 0; i <= index; i++){
//         if(ch[i] >= '0' && ch[i] <= '9'){   //如果ch[i]在0~9之間
//             Tmp_num = 0;    //先將暫存num為0
//             while(ch[i] >= '0' && ch[i] <= '9'){        //讀數字
//                 Tmp_num = Tmp_num * 10 + (ch[i] - '0');
//                 i++;
//             }
//             num[j] = Tmp_num;
//             j++;
//         }
//     }
//     printf("%s\nAns=", ch); //印出題目之字串
//     for (i = 0; i <= j; i++){   //加總
//         result += num[i];
//     }
//     printf("%d", result);
//     return 0;
// }

#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/4.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    char Tmpch;     //宣告暫存字元，用來讀檔的
    int num = 0, sum = 0;   //宣告數字和加總
    while(fscanf(fp, "%c", &Tmpch) != EOF){     //一個字元一個字元慢慢讀
        printf("%c", Tmpch);    //順便印出
        if(Tmpch >= '0' && Tmpch <= '9'){   //如果讀到數字
            fseek(fp, -1, SEEK_CUR);    //檔案指標往前一個
            fscanf(fp, "%d", &num);     //讀入數字
            sum += num;     //直接加總
        }
    }
    printf("\nAns=%d", sum);    //印出加總
    fclose(fp);
    return 0;
}