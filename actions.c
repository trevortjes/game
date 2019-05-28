#include "includes.h"

char normalCases[10][100]=
{
    {"You hear gunfire in the distance, better evade the battle"},
    {"You see fallen soldiers, at least what is left of them..."},
    {"You see a destroyed house, people used to live there"},
    {"You see an abandoned tank, destroyed by antitank artillery"},
    {"You see children sitting in a row against a wall, all brutally executed"},
    {"You see a teddy bear laying on the ground, the dead owner too"},
    {"You hear planes flying over, better hide for a while"},
    {"You see someone running in the distance, seconds before getting killed"},
    {"You think of home"},
    {"You started to daydream but got interrupted by the sound of gunfire"},
};

char closerCases[3][100]=
{
    {"You see a flag of your country, getting closer to safety"},
    {"You hear people speaking your language in the distance"},
    {"No sign of enemies, must be getting closer"},

};

void looting()
{
    int r = rand() % 99;//Calculates percentage

    if(r>50)//If percentage is higher than 50%
    {
        getItem();//Find an item
    }
    else//If percentage is lower than 50%
    {
        scr("you found nothing...",0);//Find nothing
    }
    //energy-=10;//Looting costs 10 energy
}

void params()
{
    printf("\n(Health: %d | Hunger: %d | Thirst: %d | Sanity: %d | Energy: %d)\n\n", health, hunger, thirst, sanity, energy);//Prints all parameters
}

void death()
{
    //Sequence for committing suicide
    scr("...",0);
    delay(1000);
    printf("\nYou committed suicide\n\n");
    delay(1000);
    printf("Dogtag:\n");
    delay(1000);
    me();
    delay(1000);
    exit(0);
}

void sleep()
{
    //makes sure energy is capped at 100
    if(energy<100)
    {
        energy+=30;
    }
    if (energy>100)
    {
        energy=100;
    }

    //makes sure sanity is capped at 100
    if(sanity<100)
    {
        sanity+=5;
    }
    if (sanity>100)
    {
        sanity=100;
    }

    //hunger-=20;//Get hungry while sleeping
    //thirst-=15;//Get thirsty while sleeping
    scr("You slept well",0);
    xp+=5;
}

void inv()
{
    //Shows inventory
    printf("\n #\tItem\n");
    for(int i=0; i<5; i++)//A user can have 5 items max
    {
        printf("(%d)\t%s\n",i+1,inventory[i]);
    }
    printf("\n");
}

void getItem()
{
    unsigned char items[3][10]= {"bread","bandaid","water"};//Available loot
    unsigned char r = rand() % 3;//Choose random loot
    int full = 0;//To check if the inventory is full

    for(int j=0; j<5; j++)//Checks inventory spaces
    {
        if(strcmp(inventory[j], "---") == 0)//If a space is empty
        {
            full =0;//Set full flag to 0
            break;//Get out of the function
        }
        else//If theres no space left
        {
            full=1;//Set full flag to 1
        }
    }

    if(full==0)//If the inventory isn't full
    {
        for(int i = 0; i<5; i++)//Find the first empty spot in the inventory
        {
            if (strcmp(inventory[i], "---") == 0)
            {
                strcpy(inventory[i],items[r]);//Put the loot in the spot
                break;//Get out of the function
            }
        }
        scr("you found:", items[r]);//Tell the user what was found
        xp+=10;
    }
    else
    {
        scr("Your inventory is full",0);//Tell the user their inventory is full
    }


}

void removeItem()
{
    int n,valid;
    printf("insert number: ");//Ask for inventory slot to clear
    scanf("%d",&n);


    if(n>=1 && n<=5)
    {
        valid = 1;
    }

    if (valid == 1)
    {
        if(strcmp(inventory[n-1], "---") != 0)//If the chosen slot is full
        {
            printf("You threw the %s away\n\n",inventory[n-1]);//Remove it by setting it to ---
            strcpy(inventory[n-1],"---");
        }
        else//If the spot is already empty
        {
            scr("There is nothing to throw away",0);//Tell the user it is empty
        }

    }
    else
    {
        scr("Invalid slot",0);
    }

}

void gunCheck()
{
    if (strcmp(gun,"---")==0) //Check if the user does not have a gun
    {
        scr("Youre wielding nothing",0);//Tell the user there is no gun available
    }
    else  //If there is a gun
    {
        printf("You are currently wielding a %s\n", gun);
    }//Tell the user they have a gun and what it is
}

void me()
{
    printf("NAME: %s\nSCORE: %d\n",name,xp);//Gives the player general information
}

void walk()//movement
{
    int r = rand() % 99;
    if(r<=30)//rare case closer to end
    {

        int rcloser = rand() % 3;
        scr(closerCases[rcloser],0);

        story1++;
    }
    else if (r>30 && r<=80)//normal case nothing interesting
    {
        int rnormal = rand() % 10;
        scr(normalCases[rnormal],0);
        sanity-=10;
    }
    else if (r>80 && r<=90)//Getting lost
    {
        printf("You got lost\n");
        story1--;
        if(story1<=0)
        {
            story1=0;
        }
        sanity-=1;
    }
    else if (r>90)//rare case enemy
    {
        enemy();
    }
    //printf("%d\n",story1);
}

void enemy()
{
    char action[5];
    scr("shit, spotted by the enemy! (flee) or (fight)?",0);

    while(strcmp(action,"flee")!=0 && strcmp(action,"fight")!=0)
    {
        printf("Command: ");
        scanf("%s",&action);
    }

    if (strcmp(action,"flee")==0)
    {
        scr("You fled like a coward",0);
        scr("You got wounded while doing so",0);
        health-=30;
    }
    else if (strcmp(action,"fight")==0)
    {
        if(ammo==0)
        {
            scr("You have no ammo, you had to flee",0);
            scr("You got wounded while doing so",0);
            sanity-=20;
            health-=10;
            xp-=20;
        }
        else
        {
            scr("You killed the soldier",0);
            delay(100);
            scr("You immediately wonder how his family will react",0);
            xp+=100;
            sanity-=10;
            ammo--;
        }
    }


}


