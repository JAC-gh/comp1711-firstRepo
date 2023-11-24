#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <math.h>

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
    // initialises array of structs
    FITNESS_DATA data[150];
    // initialises required variables
    char userChoice;
    int i=0, totalSteps=0, indexOfLowest=0, indexOfMax=0, meanSteps;
    int max500, current500, max500Start, current500Start, max500End;
    char filename[25], fileOut[50], dateOfSteps[11], timeOfSteps[6], noOfSteps[7];
    FILE *fileCheck;
    //loops forever until user exits through Q or code forced to quit
    while (1){
        //displays menu options
        printf("Menu Options:\nA: Specify the filename to be imported\
                \nB: Display the total number of records in the file\
                \nC: Find the date and time of the timeslot with the fewest steps\
                \nD: Find the date and time of the timeslot with the largest number of steps\
                \nE: Find the mean step count of all records in the file\
                \nF: Find the longest continuous period where the step count is above 500 steps\
                \nQ: Quit\nEnter Choice:");
        //takes in user input
        scanf("%c", &userChoice);
        //stops scanf from using leftover return character from entry in future loops
        while (userChoice == '\n'){
            scanf("%c", &userChoice);
        }
        //switch statement based on user input
        switch (userChoice){
            case 'A':
                i = 0;
                totalSteps = 0;
                indexOfLowest = 0;
                indexOfMax = 0;
                meanSteps = 0;
                max500 = 0;
                current500 = 0;
                max500Start = 0;
                current500Start = 0;
                max500End = 0;
                //tries to open file using name input by user
                printf("Input filename: ");
                scanf("%s", filename);
                FILE *fileCheck = fopen(filename, "r");
                if (fileCheck == NULL){
                    //returns error if file not found
                    printf("Error: Could not find or open file.\n");
                    return 1;
                }
                //loop to read content out of the file
                while (fgets(fileOut, 50, fileCheck) != NULL){
                    tokeniseRecord(fileOut, ",", dateOfSteps, timeOfSteps, noOfSteps);
                    strcpy(data[i].date, dateOfSteps);
                    strcpy(data[i].time, timeOfSteps);
                    data[i].steps = atoi(noOfSteps);
                    if (atoi(noOfSteps) < data[indexOfLowest].steps){
                        //keeps track of the record with lowest step count via index in data
                        indexOfLowest = i;
                    }
                    if (atoi(noOfSteps) > data[indexOfMax].steps){
                        //keeps track of the record with highest step count via index in data
                        indexOfMax = i;
                    }
                    //updates total step count
                    totalSteps += atoi(noOfSteps);
                    if (atoi(noOfSteps) > 500){
                        if (current500 == 0){
                            //updates start of current 500+ streak
                            current500Start = i;
                        }
                        //updates length of current 500+ streak
                        current500 += 1;
                    }
                    else if (atoi(noOfSteps) <= 500){
                        if (current500 != 0){
                            //checks if completed 500+ streak is longer than previous best
                            if (current500 > max500){
                                //if it is, updates stats for longest streak
                                max500 = current500;
                                max500Start = current500Start;
                            }
                        }
                        //resets length of current 500+ streak
                        current500 = 0;
                    }
                    //updates record count
                    i++;
                }
                fclose(fileCheck);
                //calculates mean steps
                meanSteps = round(totalSteps/i);
                //holds index of the last record in the longest 500+ streak
                max500End = max500Start + max500 - 1;
                break;
            case 'B':
                //prints total number of records in the file
                printf("Total Records: %d\n", i);
                break;
            case 'C':
                //prints date and time of record with the lowest steps in the file
                printf("Fewest Steps: %s %s\n", data[indexOfLowest].date, data[indexOfLowest].time);
                break;
            case 'D':
                //prints date and time of record with the highest steps in the file
                printf("Largest Steps: %s %s\n", data[indexOfMax].date, data[indexOfMax].time);
                break;
            case 'E':
                //prints mean steps of entire file
                printf("Mean Step Count: %d\n", meanSteps);
                break;
            case 'F':
                //prints date and time of start and end of the 500+ streak
                printf("Longest Period Start: %s %s\n", data[max500Start].date, data[max500Start].time);
                printf("Longest Period End: %s %s\n", data[max500End].date, data[max500End].time);
                break;
            case 'Q':
                //exits program and returns 0
                return 0;
            default:
                //prints 'error' message if user input not between A-F or Q and reoutputs menu
                printf("Invalid Option...Please Try Again...\n\n");
                break;
        }
    }
}


