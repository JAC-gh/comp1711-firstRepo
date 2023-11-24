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
    //initialise variables + arrays
    FitnessData data[200];
    int i = 0, noOfSteps, j, tempSteps;
    char dateOfSteps[11], timeOfSteps[6], fileOut[50], filename[35], tempDate[11], tempTime[6];
    bool swapMade = true;
    //take user input as filename and open file
    printf("Enter Filename: ");
    scanf("%s", filename);
    FILE *csvFile = fopen(filename, "r");
    //throw error if file not found
    if (csvFile == NULL){
        printf("Error: invalid file\n");
        return 1;
    }
    //read data from file into an array
    while (fgets(fileOut, 50, csvFile) != NULL){
        //set values as "NULL" until overwritten, allows check for correct number of elements
        strcpy(dateOfSteps, "NULL");
        strcpy(timeOfSteps, "NULL");
        noOfSteps = -1;
        tokeniseRecord(fileOut, ',', dateOfSteps, timeOfSteps, &noOfSteps);
        //putting data into the array
        strcpy(data[i].date, dateOfSteps);
        strcpy(data[i].time, timeOfSteps);
        data[i].steps = noOfSteps;

        //check that date is in xxxx-xx-xx format, with x being from 0-9
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
                        //value considered invalid if not between 0-9
                        default:
                            strcpy(dateOfSteps, "NULL");
                            break;
                    }   
                }
                //checks for hyphens in format
                if ((j == 4) || (j == 7)){
                    if (dateOfSteps[j] != '-'){
                        strcpy(dateOfSteps, "NULL");
                    }
                }
            }
            //checks for xx:xx format, with x being between 0-9
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
                            //time considered invalid if chracters not between 0-9
                                strcpy(timeOfSteps, "NULL");
                                break;
                        }
                    }
                    //checks for colon in time format
                    if (j == 2){
                        if (timeOfSteps[j] != ':'){
                            strcpy(timeOfSteps, "NULL");
                        }
                    }
                }
            }
            //returns error if any data is considered invalid
            if ((dateOfSteps == "NULL") || (timeOfSteps == "NULL") || (noOfSteps == -1)){
                printf("Error: invalid file\n");
                return 1;
            }
            i++;
        }
    }

    //closes first data file
    fclose(csvFile);

    //bubble sort to descending order of steps
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
    //adds .tsv extension to old filename
    strcat(filename, ".tsv");
    //creates tsv file open for writing
    FILE *tsvFile = fopen(filename, "w");
    //loops through data array and outputs each record to a line in the .tsv file
    for (j = 0; j < i; j++){
        fprintf(tsvFile, "%s\t%s\t%d\n", data[j].date, data[j].time, data[j].steps);
    }
    //closes .tsv file and exits correctly
    fclose(tsvFile);
    return 0;
}
