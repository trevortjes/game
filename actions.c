#include "actions.h"
#include "main.h"
#include "various.h"

void looting()
{
    int r = rand() % 99;

    if(r>50)
    {
        getItem();
    }
    else
    {
        scr("you found nothing...",0);
    }
    //energy-=10;
}

void params()
{
    printf("\n(Health: %d | Hunger: %d | Thirst: %d | Sanity: %d | Energy: %d)\n\n", health, hunger, thirst, sanity, energy);
}

void death()
{
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
    if(energy<100)
    {
        energy+=30;
    }
    if (energy>100)
    {
        energy=100;
    }

    if(sanity<100)
    {
        sanity+=5;
    }
    if (sanity>100)
    {
        sanity=100;
    }

    //hunger-=20;
    //thirst-=15;
    scr("You slept well",0);
}

void inv()
{
    printf("\n #\tItem\n");
    for(int i=0; i<5; i++)
    {
        printf("(%d)\t%s\n",i+1,inventory[i]);
    }
    printf("\n");
}

void getItem()
{
    char items[3][10]= {"bread","bullet","water"};
    char r = rand() % 3;
    int full = 0;

    for(int j=0; j<5; j++)
    {
        if(strcmp(inventory[j], "---") == 0)
        {
            full =0;
            break;
        }
        else
        {
            full=1;
        }

    }

    if(full==0)
    {
        for(int i = 0; i<5; i++)
        {
            if (strcmp(inventory[i], "---") == 0)
            {
                strcpy(inventory[i],items[r]);

                break;
            }
        }
        scr("you found", items[r]);
    }
    else
    {
        scr("Your inventory is full",0);
    }


}

void removeItem()
{
    int n;
    printf("insert number: ");
    scanf("%d",&n);
    printf("You threw the %s away\n\n",inventory[n-1]);
    strcpy(inventory[n-1],"---");

}



