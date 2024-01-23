#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num){     //  判斷是否為質數的函式
    if(num == 2){
        return true;
    }
    int i = 2;
    for (i = 2; i < num; i++){
        if(num % i == 0){   //  如果可以被2以上 num以下的任何數字整除，救回傳0
            return false;
        }
    }
    return true;    //  能跑到這裡代表都沒被整除過，即是質數
}

int main(){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\1.txt", "r");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    int num = 0, i = 2, index = 0, count[100] = {0}, prime[100] = {0};
    bool flag = false;
    fscanf(fp, "%d", &num);     //  讀入數字
    printf("%d\n", num);    //  印出該數字
    fclose(fp);
    while(num != 1){    //  分解到最後一定為1，所以設為不等於1
        if(is_prime(i)){    //  如果是質數  
            while(num % i == 0){    //  如果可以被整除執行
                num /= i;   //  分解
                count[index]++;     //  每分解一次計數器+1
                flag = true;    //  將旗子立起，表示有被分解過
            }
            if(flag){   //  如果被分解過
                prime[index] = i;   //  將質數存起來
                index++;    //質數陣列的所印+1
            }
            flag = false;   //  初始化旗子
        }
        i++;
    }
    //印出答案
    printf("Ans=");
    for (i = index - 1; i >= 0; i--){
        printf("%d(%d)", prime[i], count[i]);
    }

    return 0;
}