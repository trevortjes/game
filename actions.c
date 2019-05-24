#include "actions.h"
#include "main.h"
#include "various.h"

void looting()
{
    int r = rand() % 99;
    if(r>50)
    {
        scr("you found an item!",0);
    }
    else
    {
        scr("you found nothing...",0);
    }
    energy-=10;
}

void params()
{
    printf("\n(Health: %d | Hunger: %d | Thirst: %d | Sanity: %d | Energy: %d)\n\n",health,hunger,thirst,sanity, energy);
}

void death()
{
    printf("You committed suicide");
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

    hunger-=20;
    thirst-=15;
    scr("You slept well",0);
}
