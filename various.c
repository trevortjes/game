#include "includes.h"

void delay(int ms)
{
    // Converting time into milli_seconds
    int milli_seconds = ms;

    //Setting the start time
    clock_t start_time = clock();

    // looping till required time is achieved
    while (clock() < start_time + milli_seconds)
        ;
}

/*
@TODO maybe add a third parameter
*/
void scr(char* s, char* v)
{
    while(*s != '\0')//Checks if the end of a string is not reached yet
    {
        printf("%c",*s);//Print all the characters in the string with delay
        delay(30);
        s++;
    }

    if (v!=0)//Same but for the second segment
    {
        printf(" ");
        while(*v != '\0')
        {
            printf("%c",*v);
            delay(30);
            v++;
        }
    }
    printf("\n");
    delay(500);
}
/*
@TODO name check, make it secure but also more interesting
*/
void introduction()
{
    //Introduction sequence
    scr("Are you awake?",0);
    scr("Good, you appeared to be dead",0);
    scr("Let me help you get up...",0);
    scr("What is your name?",0);
    printf("Name: ");
    scanf("%s",&name);
    scr("So your name is",name);
    scr("I used to know a",name);
    scr("But let's not get sidetracked...",0);
    scr("Do you remember the attack?",0);
    scr("Those assholes bombed us",0);
    scr("I lost all my men but found you",0);
    scr("Take a look around, you might find something",0);
    delay(1000);
    params();
    delay(1000);
}


void parser()
{
    printf("Command: ",0);
    char com[]= {};
    scanf("%s",&com);//Asks for a command

    if (strcmp(com, "loot") == 0 || strcmp(com, "l") == 0 )//Looting
    {
        looting();
    }
    else if (strcmp(com, "die") == 0)//Suicide
    {
        death();
    }
    else if (strcmp(com, "parameters") == 0 || strcmp(com, "p") == 0)//Check params
    {
        params();
    }
    else if (strcmp(com, "sleep") == 0)//Sleep
    {
        sleep();
    }
    else if (strcmp(com, "remove") == 0 || strcmp(com, "rm") == 0 )//Remove an item from inventory
    {
        removeItem();
    }
    else if (strcmp(com, "inventory") == 0 || strcmp(com, "inv") == 0)//Check inventory
    {
        inv();
    }
    else if (strcmp(com, "gun") == 0 || strcmp(com, "weapon")==0)//Check current weapon
    {
        gunCheck();
    }
    else if (strcmp(com, "me") == 0)//Check general stuff
    {
        me();
    }
    else
    {
        printf("You seem to not know what to do\n");//When an unknown command is used
    }
}

