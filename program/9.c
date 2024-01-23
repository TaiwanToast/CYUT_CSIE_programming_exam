#include <stdio.h> 

int main(void){
	FILE *fp;
	fp = fopen("D:/.Vscode/C/porgram_C/txt/9.txt", "r");
	if(fp == NULL){
		printf("error");
		return 1;
	}
	char ch[100] = {'\0'}, result[100] = {'\0'};
	int index = 0, i = 0, count = 0;
	while(fscanf(fp, "%c", &ch[index]) != EOF){		//讀入題目，順便印出
		printf("%c", ch[index]);
		index++;
	}
	fclose(fp);
	for (i = 0; i < index; i++){
		if(ch[i] == 'x'){	//如果遇到小炸彈，將自己以及前後各一個改成"-"
			result[i] = '-';
			result[i + 1] = '-';
			result[i - 1] = '-';
		}
		else if(ch[i] == 'X'){	//如果遇到大炸彈，將自己以及前後各兩個改成"-"
			result[i] = '-';
			result[i + 1] = '-';
			result[i - 1] = '-';
			result[i + 2] = '-';
			result[i - 2] = '-';
		}
	}
	printf("\n");
	for (i = 0; i < index; i++){	//計算安全區域
		if(result[i] != '-'){	//沒被炸到的地方就是安全區域
			count++;
		}
	}
	printf("Ans=%d", count);
	return 0;
}