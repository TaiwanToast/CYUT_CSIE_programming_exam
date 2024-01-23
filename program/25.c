// #include <stdio.h>

// int main(void){
//     FILE *fp;
//     fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\25.txt", "r");

//     if(fp == NULL){
//         printf("error open file.");
//         return 1;
//     }

//     int A_animal_legs = 0, B_animal_legs = 0, total_head = 0, total_leg = 0;
//     fscanf(fp, "%d %d %d %d", &A_animal_legs, &B_animal_legs, &total_head, &total_leg);
//     fclose(fp);
    
//     int A_animal = 0, B_animal = 0, break_flag = 0;
//     for (int i = 1; i <= total_head; i++){
//         for (int j = 1; j <= total_head; j++){
//             // A動物的總腳數 * A動物總數 + B動物的總腳數 * B動物總數 = 總腳數
//             // A動物總數 + B動物總數 = 總頭數
//             // 以上兩個條件達到即是答案
//             if(A_animal_legs * i + B_animal_legs * j == total_leg && i + j == total_head){
//                 A_animal = i;
//                 B_animal = j;
//                 break_flag = 1;
//                 break;
//             }
//         }
//         if(break_flag){
//             break;
//         }
//     }
//     // 印出題目與答案
//     A_animal && B_animal ? printf("%d %d %d %d\nAns=%d %d", A_animal_legs, B_animal_legs, total_head, total_leg, A_animal, B_animal) : printf("%d %d %d %d\nAns=No Solution", A_animal_legs, B_animal_legs, total_head, total_leg);
//     return 0;
// }

#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("D:\\.Vscode\\C\\porgram_C\\txt\\25.txt", "r");

    if(fp == NULL){
        printf("error open file.");
        return 1;
    }

    int A_animal_legs = 0, B_animal_legs = 0, total_head = 0, total_leg = 0;
    fscanf(fp, "%d %d %d %d", &A_animal_legs, &B_animal_legs, &total_head, &total_leg);
    fclose(fp);

    int A_animal = 0, B_animal = 0;
    for (int i = 1; i <= total_head; i++){
        if(i + total_head == total_leg / 2){
            B_animal = i;
            A_animal = total_head - B_animal;
            break;
        }
    }

    A_animal && B_animal ? printf("%d %d %d %d\nAns=%d %d", A_animal_legs, B_animal_legs, total_head, total_leg, A_animal, B_animal) : printf("%d %d %d %d\nAns=No Solution", A_animal_legs, B_animal_legs, total_head, total_leg);

    return 0;
}