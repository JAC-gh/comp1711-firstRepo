#include "utilities.h"
#include <string.h>



int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice, monthInp[4], monthFile[4];
    int counter = 0, i = 0, j = 0;
    float mean = 0, maxBlood = 0, minBlood = 100;

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }

    counter = 0;
    while (fgets(line, buffer_size, input)){
        tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
        counter++;
    }

    for (i = 0; i < counter; i++){
    //B
    mean += daily_readings[i].bloodIron;
    //C
    if (daily_readings[i].bloodIron > maxBlood){
        maxBlood = daily_readings[i].bloodIron;
    }
    //D
    if (daily_readings[i].bloodIron < minBlood){
        minBlood = daily_readings[i].bloodIron;
    }

    }

    while (1)
    {

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            break;

        case 'B':
        case 'b':
            mean /= counter;
            printf("Your average blood iron was %.2f\n", mean);
            break;

        case 'C':
        case 'c':
            printf("Min blood iron was %.1f\n", minBlood);
            break;

        case 'D':
        case 'd':
            printf("Max blood iron was %.1f\n", maxBlood);
            break;

        case 'E':
        case 'e':
            printf("Enter the month (JAN/FEB/MAR...): ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", monthInp);
            for (i = 0; i < counter; i++){
                for (j = 0; j < 3; j++){
                    monthFile[j] = daily_readings[i].date[3 + j];
                }
                if (strcmp(monthInp, monthFile) == 0){
                    printf("%s,%.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
                }
            }
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}