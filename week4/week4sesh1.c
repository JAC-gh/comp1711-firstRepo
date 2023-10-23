#include <stdio.h>
#include <stdlib.h>



float StarterTask(){
    int numEntered[10];
    int total = 0, i;
    float mean;
    for (i=0; i < 10; i++){
        printf("Enter a number :");
        scanf("%d", &numEntered[i]);
        total += numEntered[i];
    }
    mean = total / 10;
    return mean;
}

int EnterNumToFile(){
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        perror("");
        return 1;
    }
    int number, num_lines = 10, total;
    float mean;
    printf("How many numbers  to enter: ");
    scanf("%d", &num_lines);
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
        total += number;
    }
    mean = total / num_lines;
    fprintf(file, "%f\n", mean);
    fclose(file);
    return 0;
}


int CreateDatFile(){
    char datFile[] = "squares.dat";
    FILE *file = fopen(datFile, "w");
    if (file == NULL){
        printf("ERROR...");
        return 1;
    }
    int i, numToSquare;
    printf("Enter how many numbers you would like to square: ");
    scanf("%d", &numToSquare);
    for (i=1; i < numToSquare + 1; i++){
        fprintf(file, "%d\n", i*i);
    }
    fclose(file);
    return 0;
}

int ReadFromFile(){
    char datFile[] = "squares.dat";
    FILE *file = fopen(datFile, "r");
        if (file == NULL){
        printf("ERROR...");
        return 1;
    }
    char fileOut[50];
    int total = 0;
    float mean, i;
    while (fgets(fileOut, 50, file) != NULL){
        total += atoi(fileOut);
        i++;
    }
    mean = total / i;
    printf("%f\n", mean);
    fclose(file);
    return 0;
}


int UpdateFile(){
    char datFile[] = "squares.dat";
    FILE *file = fopen(datFile, "a+");
    if (file == NULL){
        printf("ERROR...");
        return 1;
    }
    char fileOut[50];
    float mean, i, total;
    while (fgets(fileOut, 50, file) != NULL){
        total += atof(fileOut);
        i++;
    }
    mean = total / i;
    fprintf(file, "\n%f", mean);
    fclose(file);
}


void main(){
    UpdateFile();
}