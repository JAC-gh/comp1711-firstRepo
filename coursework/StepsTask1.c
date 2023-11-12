#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FITNESS_DATA data[150];
    FILE* csvFile = fopen("FitnessData_2023.csv", "r");

    char fileOut[50], dateOfSteps[11], timeOfSteps[6], noOfSteps[7];
    int i;
    while (fgets(fileOut, 50, csvFile) != NULL){
        tokeniseRecord(fileOut, ",", dateOfSteps, timeOfSteps, noOfSteps);
        strcpy(data[i].date, dateOfSteps);
        strcpy(data[i].time, timeOfSteps);
        data[i].steps = atoi(noOfSteps);
        i++;
    }

    printf("Number of records in file: %d\n", i);
    for (i = 0; i < 3; i++){
    printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(csvFile);
    return 0;
}
