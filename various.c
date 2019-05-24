#include "various.h"
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
        delay(50);
        s++;
    }

    if (v!=0)
    {
        printf(" ");
        while(*v != '\0')
        {
            printf("%c",*v);
            delay(40);
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
    printf("I want to: ");
    char com[]= {};
    scanf("%s",&com);

    hunger--;
    thirst--;
    sanity--;
    energy--;

    if (strcmp(com, "loot") == 0)
    {
        looting();
    }
    else if (strcmp(com, "die") == 0)
    {
        death();
    }
    else if (strcmp(com, "check") == 0)
    {
        params();
    }
    else if (strcmp(com, "sleep") == 0)
    {
        sleep();
    }
    else
    {
        printf("invalid input\n");
    }
}
