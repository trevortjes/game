#include "various.h"
#include "actions.h"
#include "main.h"
#include <time.h>

void delay(int ms)
{
    // Converting time into milli_seconds
    int milli_seconds = ms;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}

void scr(char* s, char* v)
{
    while(*s != '\0')
    {
        printf("%c",*s);
        delay(30);
        s++;
    }

    if (v!=0)
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

void introduction()
{
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
    scanf("%s",&com);

    hunger--;
    thirst--;
    sanity--;
    energy--;

    if (strcmp(com, "loot") == 0 || strcmp(com, "l") == 0 )
    {
        looting();
    }
    else if (strcmp(com, "die") == 0)
    {
        death();
    }
    else if (strcmp(com, "parameters") == 0 || strcmp(com, "p") == 0)
    {
        params();
    }
    else if (strcmp(com, "sleep") == 0)
    {
        sleep();
    }
    else if (strcmp(com, "remove") == 0 || strcmp(com, "rm") == 0 )
    {
        removeItem();
    }
    else if (strcmp(com, "inventory") == 0 || strcmp(com, "inv") == 0)
    {
        inv();
    }
    else if (strcmp(com, "gun") == 0 || strcmp(com, "weapon")==0)
    {
        gunCheck();
    }
    else if (strcmp(com, "me") == 0)
    {
        me();
    }
    else
    {
        printf("You seem to not know what to do\n");
    }
}

