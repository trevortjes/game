#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int health=100, hunger=100, thirst=100, sanity=100, energy=100;
char name[]= {};

int main()
{
    //introduction();
    while(1)
    {
        if(health>0 && hunger>0 && thirst>0 && sanity>0 && energy>0)
        {
            parser();
        }
        else
        {
            printf("You died\n");
            params();
            exit(0);
        }

    }
    printf("THE END");
    return 0;
}




