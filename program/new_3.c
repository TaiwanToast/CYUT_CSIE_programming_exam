#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    FILE *fp;
    fp = fopen("D:/.Vscode/C/porgram_C/txt/3.txt", "r");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    int num_index = 0, i = 0, sign_index = 0;
    double num[100] = {0.0}, result = 0.0;
    char ch, sign[100] = {'\0'};
    while((ch = fgetc(fp)) != EOF){
        if(ch >= '0' && ch <= '9'){
            fseek(fp, -1, SEEK_CUR);
            fscanf(fp, "%lf", &num[num_index]);
            num_index++;
        }else if(ch != '='){
            sign[sign_index] = ch;
            sign_index++;
        }
    }

    fclose(fp);
    result = num[0];
    for (i = 1; i <= sign_index; i++){
        
        if(sign[i-1] == '+'){
            result += num[i];
        }
        else if(sign[i-1] == '-'){
            result -= num[i];
        }
        else if(sign[i-1] == '*'){
            result *= num[i];
        }
        else if(sign[i-1] == '/'){
            result /= num[i];
        }
    }
    printf("%d", lround(result));

    return 0;
}