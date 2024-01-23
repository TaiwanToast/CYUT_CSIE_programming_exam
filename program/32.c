#include <stdio.h>
#include <string.h>

int main(void){
	FILE *fp;
	fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\32.txt", "r");

	if(fp == NULL){
		printf("error open file.");
		return 1;
	}

	char str[101] = {'\0'};
	fgets(str, 101, fp); // 因為題目說字串長度最長為100，所以用這個函式讀取整個題目即可
	fclose(fp);
	// 計算加總，順便計字數
	int index = 0, sum = 0;
	while(str[index] != '\0'){
		if(str[index] >= 'a' && str[index] <= 'z'){
			sum += (str[index] - 'a') + 1;
		}else if(str[index] >= 'A' && str[index] <= 'Z'){
			sum += (str[index] - 'A') + 1;
		}
		index++;
	}
	// 開始轉換字串
	char result[100] = {'\0'};
	int n = sum % 26; // 計算偏移輛
	for (int i = 0; i < index; i++){
		// 大小寫分開做，避免出錯
		if(str[i] >= 'a' && str[i] <= 'z'){	// 小寫部分
			int tmp = str[i] + n;	// 偏移
			if(tmp > 'z'){	// 如果偏移結果超出z
				tmp -= 26;	// 把偏移結果-26就可以偏移回字母區
			}
			result[i] = (char)tmp;
		}else if(str[i] >= 'A' && str[i] <= 'Z'){	// 小寫部分同理
			int tmp = str[i] + n;
			if(tmp > 'Z'){
				tmp -= 26;
			}
			result[i] = (char)tmp;
		}else{
			result[i] = str[i];
		}
	}
	// 印出題目與答案
	printf("%s\nAns=%s", str, result);
	return 0;
}