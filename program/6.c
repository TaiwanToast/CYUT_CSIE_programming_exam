#include <stdio.h>

int MinLCM(int lcm, int num){	//求最小公倍數的函式
	int max_com = 0;	//最大公因數
	for (int i = 1; i <= lcm && i <= num; i++){		//求出最大公因數
		if (lcm % i == 0 && num % i == 0){
			max_com = i;
		}
	}
	//最大公因數 * (第一數字 / 最大公因數) * (第二個數字 / 最大公因數) = 最小公倍數
	return max_com * (lcm / max_com) * (num / max_com);
}

int main(){
	FILE *fp;
	fp = fopen("D:/.Vscode/C/porgram_C/txt/6.txt", "r");
	if(fp == NULL){
		printf("error open file.");
		return 1;
	}
	int num[11] = {0}, index = 0, min_lcm = 0;
	while(fscanf(fp, "%d", &num[index]) != EOF){
		index++;
	}
	fclose(fp);

	for (int i = 0; i < index; i++){
		printf("%d", num[i]);
		if(i < index - 1){
			printf(" ");
		}
	}

	min_lcm = MinLCM(num[0], num[1]);	//先求出第一第二個的最小公倍數

	for (int i = 2; i < index; i++){	//再依序往下求
		min_lcm = MinLCM(min_lcm, num[i]);
	}
	
	printf("\nAns=%d", min_lcm);

	return 0;
}
/*
先求出第一第二個的最小公倍數
再依序往後求
求到最後就是答案
*/


// 第二版
/*
#include <stdio.h>

int main(void){
    FILE *fp;
	fp = fopen("D:/.Vscode/C/porgram_C/txt/6.txt", "r");
	if(fp == NULL){
		printf("error open file.");
		return 1;
	}
    int num[11] = {0}, index = 0, max_com = 0, min_lcm = 0, flag = 0;
    char q[101] = {'\0'};
    fgets(q, 100, fp);
    printf("%s\n", q);
    fseek(fp, 0, SEEK_SET);
    while(fscanf(fp, "%d", &num[index]) != EOF){
        if(flag && index > 0){
            for (int i = 1; i <= num[index - 1] && i <= num[index]; i++){
                if(num[index - 1] % i == 0 && num[index] % i == 0){
                    max_com = i;
                }
                min_lcm = max_com * (num[index - 1] / max_com) * (num[index] / max_com);
            }
        }
        index++;
        flag = 1;
    }
    fclose(fp);
    printf("Ans=%d", min_lcm);
    return 0;
}
*/