#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50     //定義輸入陣列最大的大小

struct data{    //宣告一個堆疊用結構，用於存入括號
    char datas;
}sd[MAX_SIZE];
int top = -1;   //宣告堆疊頂端

void push(char input_data){     //推入堆疊函式
    sd[++top].datas = input_data;   //頂端加一，推入堆疊
}

void pop(){     //刪除堆疊函式
    if(top < -1){   //先判斷堆疊是否已空，已空代表沒有配對
        printf("Ans=ERROR");    //輸出error
        exit(0);    //中止整個程式
    }else{  //不為空
        top--;  //頂端減一
    }
}

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\10.txt", "r");
    if(fp == NULL){
        printf("error open file.");
        return 1;
    }
    char input_data[MAX_SIZE];
    fgets(input_data, MAX_SIZE, fp);    //讀入題目
    printf("%s\n", input_data);     //輸出題目
    fclose(fp);
    int index = 0;  //宣告索引
    while(input_data[index] != '\0'){
        if(input_data[index] == '(' || input_data[index] == '[' || input_data[index] == '{'){   //如果是左括號就推入堆疊
            push(input_data[index]);
        }else if(input_data[index] == ')' || input_data[index] == ']' || input_data[index] == '}'){//右括號就刪除
            pop();
        }
        index++;
    }
    printf("%s", top == -1 ? "Ans=CORRECT" : "Ans=ERROR");      //看堆疊最後有沒有刪空，刪空代表都有配對到，否則沒有
    return 0;
}