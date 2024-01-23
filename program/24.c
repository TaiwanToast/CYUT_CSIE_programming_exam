#include <stdio.h>
#include <math.h>

double Fa(int n){	// 階乘函式，從1乘到n
	double result = 1;
	for (int i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}

double sum(int x, int n){	// 加總函式
	double _sum = 0;
	for (int k = 1; k <= n; k++){	// 依照題目要求的算式
		_sum += pow(x, k) / Fa(k);
	}
	return _sum;
}

int main(void){
	FILE *fp;
	fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\24.txt", "r");

	if(fp == NULL){
		printf("error open file.");
		return 1;
	}

	int x = 0, n = 0;
	fscanf(fp, "%d %d", &x, &n);
	fclose(fp);

	printf("%d\n%d\nAns=%d", x, n, (int)sum(x, n));		// 強制轉型就是無條件捨去了

	return 0;
}