#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    fp=fopen("D:/.Vscode/C/porgram_C/txt/22.txt","r");
    if(fp==NULL){
        printf("Error");
    }
    int count=0,num[100],sort=0,i=0,j=0,temp=0;
    fscanf(fp,"%d",&sort);//讀全部有空格就停止
    printf("%d\n",sort);
    while(fscanf(fp,"%d",&num[count])!=EOF){
    count++;
    }
    i=0;
    while(i<count){
        printf("%d",num[i]); 
        if(i<count-1){
            printf(" ");
        }
        i++;
    }
    if(sort==0){//小排大
        i=0;
        while(i<count){
            j=0;
            while(j<count-1){
                if(num[j]>num[j+1]){
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp; 
                }
                j++;  
            }
            i++;
        }
    }
    if(sort==1){//大排小
        i=0;
        while(i<count){
            j=0;
            while(j<count-1){
                if(num[j]<num[j+1]){
                    temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp; 
                }
                j++;  
            }
            i++;
        }
    }
    i=0;
    printf("\n");
    printf("Ans=");
    while(i<count){
        printf("%d",num[i]); 
        if(i<count-1){
            printf(" ");
        }
        i++;
    }
    fclose(fp);
    return 0;
}
