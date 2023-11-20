#include <stdio.h>
#include <stdlib.h>




void fillRand(int a[][4], int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; i++){
            a[i][j] = rand() % 10;
        }
    }
}

void printArray(int a[][4] ){
  for (int i = 0; i <= 2; ++i) {
     for (int j = 0; j <= 3; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

int main(){
    int array1[3][4];
    int array2[3][4];

    printArray(array1);
    fillRand(array1, 3, 4);
    printArray(array1);

    printArray(array2);
    fillRand(array2, 3, 4);
    printArray(array2);

}