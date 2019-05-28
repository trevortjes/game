#include "includes.h"

int health=100, hunger=80, thirst=100, sanity=100, energy=100, xp=0;
unsigned char name[20]= {"Ryan"};
unsigned char inventory[5][10] = {"---","---","---","---","---"};
unsigned char gun[10]="PPSH";
int ammo=1;
int story1 = 0;

int main()
{
    printf("Press any key to start\n");
    getch();  //Waits for input
    //introduction();//Starts the introduction sequence

    while(1)
    {
        if(health>0 && hunger>0 && thirst>0 && sanity>0 && energy>0)//Checks if you aren't dead
        {
            parser();//Check input
        }
        else
        {
            scr("...",0);
            delay(1000);
            printf("You died\n");//You die and the game exits when any parameter is > 0
            delay(1000);
            printf("Final parameters:\n");
            delay(1000);
            params();//Shows your final parameters
            delay(1000);
            exit(0);
        }
    }
    printf("THE END");
    return 0;
}
