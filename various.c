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
    scr("- Are you awake?",0);
    scr("- Good, you appeared to be dead",0);
    scr("- Let me help you get up...",0);
    scr("- What is your name?",0);
    printf("Name: ");
    scanf("%s",&name);
    scr("- I have never seen you here before,",name);
    scr("- Nevermind, no time for smalltalk",0);
    scr("- Do you remember the attack?",0);
    scr("- Those assholes bombed us!",0);
    scr("- We are the only ones left...",0);
    scr("- Take a look around, you might find something (loot)",0);
    delay(1000);

    char com[]= {};
    while(strcmp(com, "loot") != 0)
    {
        printf("Command: ",0);
        char com[]= {};
        scanf("%s",&com);//Asks for a command
    }
        scr("you found: Bread", 0);

    delay(500);

    scr("- Hm, moldy old bread",0);
    scr("- Well, it's better than nothing",0);
    scr("- Are you feeling hungry?",0);
    delay(500);
    params();
    delay(500);
    scr("- You sure look hungry",0);
    scr("- Go on, take a bite (eat)",0);

    com[0]= "";
    while(strcmp(com, "eat") != 0)
    {
        printf("Command: ",0);
        char com[]= {};
        scanf("%s",&com);//Asks for a command
    }

    hunger+=20;
    delay(500);
    params();
    delay(500);

    scr("- That will make you feel...", 0);
    scr("...",0);
   scr("A clean snipershot right through the skull killed the friendly soldier", 0);
    scr("It is all up to you now\n", 0);
    delay(1000);

    parser();

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

