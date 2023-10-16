#include <stdio.h>
#include <stdbool.h>

void StarterExercise(){
    int temp;
    bool jacketOn = false;
    if (temp < 14){
        jacketOn = true;
    }
    else {
        jacketOn = false;
    }
}

void IntroToIfs(){

    int mark = 40;

    if (mark >= 40)
    {
        printf ("The mark of %d is a pass\n", mark);
    }
    else
    {
        printf ("The mark of %d is a fail\n", mark);
    }
}




void MenuSwitchCase(){
    char userInp;
    printf("Main Menu \n1. Play Game\n2. Multiplayer\n3. Settings\n4. Credits\n5. Exit Game\n");
    printf("Enter the number corresponding to the option you would like to select: ");
    scanf("%c", &userInp);
    switch (userInp){
        case '1':
            printf("Loading Game...\n");
            break;
        case '2':
            printf("Connecting To Game Server...\n");
            break;
        case '3':
            printf("Loading Settings...\n");
            break;
        case '4':
            printf("Loading Credits Scene...\n");
            break;
        case '5':
            printf("Halting Game Processes...\n");
            break;
        //default case runs MenuSwitchCase for each individual incorrect character
        default:
            printf("Invalid Option...Please Try Again...\n\n");
            MenuSwitchCase();
            break;
    }
}


void WeirdInputValidation(){
    int userInp;
    while (userInp != -1){
        printf("Enter a number: ");
        scanf("%d", &userInp);
        if ((0 < userInp) && (userInp < 100)){
            printf("Number is Valid\n");
        }
    }
    printf("Termination Value Entered...Halting Program...\n");
}

void IntoToSwitch(){
    int a;
    printf("Select an option between 0 and 3: ");
    scanf("%d", &a);

    switch (a)
    {
        case 0:    
            printf ("Option 0 has been selected\n");
            break;

        case 1:     
            printf ("Option 1 has been selected\n");
            break;

        case 2: 
            printf(" Option 2 selected \n");
            break;

        case 3: 
            printf(" Option 3 selected \n");
            break;

        default:    
            printf ("Select A Valid Option\n");
            IntoToSwitch();
    }
}


void main(){
    IntoToSwitch();
}
