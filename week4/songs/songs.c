#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Holds the data for a song such as artist, title and year.
 *
 */
typedef struct
{
    int position;
    char artist[100];
    char title[100];
    char year[4];
} SONG_DATA;

/**
 * @brief Splits a line from song_data.txt into the separate data. This is adapted from the coursework code.
 *
 * @param input the line which will be split
 * @param delimiter the character which deliminates (splits up) the data
 * @param pos a pointer to where it should store the position
 * @param artist a pointer to where it should store the artist
 * @param title a pointer to where it should store the title
 * @param years a pointer to where it should store the years
 */
void tokeniseRecord(const char *input, const char *delimiter,
                    char *pos, char *artist, char *title, char *years)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(pos, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(artist, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(title, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        strcpy(years, token);
    }

    // Free the duplicated string
    free(inputCopy);
}

int main()
{
    SONG_DATA songs[100];
    int buffer_size = 250;
    char line[buffer_size];
    int counter=0;

    FILE *input = fopen("song_data.txt", "r");

    // creating some temporary storage:
    // pos will be converted to an int, but we'll be getting it as a string
    char pos[4];
    char artist[100];
    char title[100];
    char year[4];
    int i = 0;

    while (fgets(line, buffer_size, input))
    {   
        // first we will get the info from the line
        tokeniseRecord(line,",",pos,artist,title,year);
        strcpy(songs[i].artist, artist);
        songs[i].position = atoi(pos);
        strcpy(songs[i].title, title);
        strcpy(songs[i].year, year);
        i++;
    }

    printf("%d\n", i);
    return 0;
}