#include <stdio.h>
#include <math.h>
#include <string.h>


float CircleArea(float radius){
    return radius * radius * M_PI;
}


float VolSphere(float radius){
    return radius * radius * radius * M_PI * 4/3;
}

int StrLen (char inpString[]){
    int i = 0;
    while (inpString[i] != '\0'){
        i++;
    }
    return i;
}

int IsPrime(int numToCheck){
    int i;
    for (i = 2; i < numToCheck; i++){
        if (numToCheck % i == 0){
            return 1;
        }
    }
    return 0;
}

char* ConcatStrings(char string1[], char string2[]){
    char newString[strlen(string1)+strlen(string2)-2];
    int i;
    for (i = 0; i < strlen(string1); i++){
        newString[i] = string1[i];
    }
    for (i = strlen(string1); i < strlen(string2) + strlen(string1); i++){
        newString[i] = string2[i - strlen(string1)];
    }
    printf("%s\n", newString);
    return newString;
}


void main(){
    char newString;
    printf("%s\n", ConcatStrings("Juno", "Fish"));
}


/*
int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}

int main () 
{
    int y = 2;
    int z = sum(5, y); // calling our new function

    printf ("The sum of 5 and %d is %d\n", y, z);
}
*/