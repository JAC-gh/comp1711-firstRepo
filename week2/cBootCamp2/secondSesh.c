#include <stdio.h>


void ArraySum(int inpLst[]){
    int total, i;
    for (i = 0; i < 5; i++){
        total += inpLst[i];
    }
}

void arrayReverse(int inpLst[]){
    int i;
    int newLst[] = {0,0,0,0,0};
    for (i = 0; i < 5; i++){
        newLst[i] = inpLst[4 - i];
    }
}

void MaxInArray(int inpLst[]){
    int i, max;
    for (i = 0; i < 5; i++){
        if (inpLst[i] > max){
            max = inpLst[i];
        }
    }
}


void ArrayShift(int inpLst[]){
    int newLst[] = {0,0,0,0,0};
    
    for (int i = 0; i < 4; i++){
        newLst[i + 1] = inpLst[i];
    }
    newLst[0] = inpLst[4];
}



void main(){
    /*int num1, num2;
    printf("Enter a Number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    printf("%d\n", num1 + num2);*/

    /* char favAni;
    printf("Enter your favourite animal: ");
    scanf("%c", &favAni);*/
    
    /* int a;
    for (a = 0; a < 5; a++){
        printf("a = %d\n", a);
    }
    printf("EndOfLoop... a = %d\n", a); */

    /* int a;
    while (a < 5){
        printf("a = %d\n", a);
        a++;
    }
    printf("EndOfLoop... a = %d\n", a); */

    /* int a, b;
    for (a = 1; a < 13; a++){
        for (b = 1; b < 13; b++){
            printf("%dx%d = %d, ", a, b, a*b);
        }
        printf("\n");
    } */

}

