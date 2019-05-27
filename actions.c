#include "includes.h"

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
    printf("You committed suicide\n");
    delay(1000);
    printf("Final parameters:\n");
    delay(1000);
    params();//Shows your final parameters
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
    char items[3][10]= {"bread","bullet","water"};//Available loot
    char r = rand() % 3;//Choose random loot
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
        scr("you found", items[r]);//Tell the user what was found
    }
    else
    {
        scr("Your inventory is full",0);//Tell the user their inventory is full
    }


}

void removeItem()
{
    int n;
    printf("insert number: ");//Ask for inventory slot to clear
    scanf("%d",&n);


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

void gunCheck()
{
    if (strcmp(gun,"---")==0){//Check if the user does not have a gun
        scr("Youre wielding nothing",0);//Tell the user there is no gun available
    }else{//If there is a gun
printf("You are currently wielding a %s\n", gun);}//Tell the user they have a gun and what it is
}

void me()
{
    printf("NAME: %s\nXP: %d\n",name,xp);//Gives the player general information
}
