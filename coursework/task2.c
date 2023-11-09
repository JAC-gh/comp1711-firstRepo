#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    while (1){
        char userChoice;
        int i, meanSteps;
        char filename[20], fileOut[20], perStart[20], perEnd[20];
        printf("Menu Options:\nA: Specify the filename to be imported\
                \nB: Display the total number of records in the file\
                \nC: Find the date and time of the timeslot with the fewest steps\
                \nD: Find the date and time of the timeslot with the largest number of steps\
                \nE: Find the mean step count of all records in the file\
                \nF: Find the longest continuous period where the step count is above 500 steps\
                \nQ: Quit\nEnter Choice:");
        scanf("%c", &userChoice);
        switch (userChoice){
            case 'a':
                printf("Input filename: ");
                scanf("%s", filename);
                continue;
            case 'b':
                printf("Total Records: %d", i);
                continue;
            case 'c':
                printf("Fewest Steps: %s", fileOut);
                continue;
            case 'd':
                printf("Largest Steps: %s", fileOut);
                continue;
            case 'e':
                printf("Mean Step Count: %d", meanSteps);
                continue;
            case 'f':
                printf("Longest Period Start: %s\
                        Longest Period End: %s", perStart, perEnd);
                continue;
            case 'q':
                return 0;
        }
    }
}

