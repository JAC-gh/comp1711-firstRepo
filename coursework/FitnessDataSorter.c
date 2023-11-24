#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {

    int i = 0, noOfSteps, j;
    FitnessData data[200];
    char dateOfSteps[11], timeOfSteps[6], fileOut[50], filename[35];

    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *csvFile = fopen(filename, "r");
    if (csvFile == NULL){
        printf("Error: invalid file\n");
        return 1;
    }
    while (fgets(fileOut, 50, csvFile) != NULL){
        strcpy(dateOfSteps, "NULL");
        strcpy(timeOfSteps, "NULL");
        noOfSteps = -1;
        tokeniseRecord(fileOut, ',', dateOfSteps, timeOfSteps, &noOfSteps);
        strcpy(data[i].date, dateOfSteps);
        strcpy(data[i].time, timeOfSteps);
        data[i].steps = noOfSteps;

        //xxxx-xx-xx
        if (strlen(dateOfSteps) == 10){
            for (j = 0; j < 10; j++){
                if ((0 <= j <= 3) || (5 <= j <= 6) || (8 <= j <= 9)){
                    switch (dateOfSteps[j]){
                        case '0':
                        case '1':
                        case '2':
                        case '3':
                        case '4':
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                        case '9':
                            continue;
                        default:
                            strcpy(dateOfSteps, "NULL");
                            break;
                    }   
                }
                if ((j == 4) || (j == 7)){
                    if (dateOfSteps[j] != '-'){
                        strcpy(dateOfSteps, "NULL");
                    }
                }
            }

            if (strlen(timeOfSteps) == 5){
                for (j = 0; j < 5; j++){
                    if ((0 <= j <= 1) || (3 <= j <= 4)){
                        switch (timeOfSteps[j]){
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9':
                                continue;
                            default:
                                strcpy(timeOfSteps, "NULL");
                                break;
                        }
                    }

                    if (j == 2){
                        if (timeOfSteps[j] != ':'){
                            strcpy(timeOfSteps, "NULL");
                        }
                    }
                }
            }
            //credit tom wood
            if ((dateOfSteps == "NULL") || (timeOfSteps == "NULL") || (noOfSteps == -1)){
                printf("Error: invalid file\n");
                return 1;
            }
            i++;
        }
    }
    fclose(csvFile);

    bool swapMade = true;
    char tempDate[11], tempTime[6];
    int tempSteps;
    while (swapMade == true){
        swapMade = false;
        for (j = 0; j < i-1; j++){
            if (data[j].steps < data[j+1].steps){
                strcpy(tempDate, data[j].date);
                strcpy(tempTime, data[j].time);
                tempSteps = data[j].steps;

                strcpy(data[j].date, data[j+1].date);
                strcpy(data[j].time, data[j+1].time);
                data[j].steps = data[j+1].steps;

                strcpy(data[j+1].date, tempDate);
                strcpy(data[j+1].time, tempTime);
                data[j+1].steps = tempSteps;

                swapMade = true;
            }
        }
    }
    //write to new file (tsv)
    strcat(filename, ".tsv");
    FILE *tsvFile = fopen(filename, "w");
    for (j = 0; j < i; j++){
        fprintf(tsvFile, "%s\t%s\t%d\n", data[j].date, data[j].time, data[j].steps);
    }
    fclose(tsvFile);

}
