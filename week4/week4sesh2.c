#include <stdio.h>
#include <stdlib.h>

int StarterAct(){
    char filename[] = "input.txt";
    FILE* file = fopen(filename,"r+");
    if (file == NULL){
        printf("Error");
        return 1;
    }
    char fileOut[200];
    int numList[200], i = 0, count = 0;
    while (fgets(fileOut, 200, file) != NULL){
        printf("%s", fileOut);
        numList[i] = atoi(fileOut);
        if (atoi(fileOut) > 1000){
            count++;
        }
        i++;
    }
    fclose(file);
    printf("%i\n", count);
    return 0;
}



struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    char DOB [8];
    int mark [3];
};









void main () {
    /*struct student jamie;
    printf("Enter your first name: ");
    scanf("%s", jamie.name);
    printf("Enter your student ID: ");
    scanf("%s", jamie.student_id);
    printf("Enter your DOB (dd/mm/yy): ");
    scanf("%s", jamie.DOB);
    printf("Enter your mark: ");
    scanf("%d", jamie.mark);



    printf("\nStudent name: %s\n", jamie.name);
    printf("Student ID:   %s\n", jamie.student_id);
    printf("DOB:  %s\n", jamie.DOB);
    printf("Final mark:   %d\n", *jamie.mark); */

}






