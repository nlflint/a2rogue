//
// Created by Nathan Flint on 12/29/19.
//

#include "random.h"
#include <stdlib.h>

int rnd(int max) {
    if (max == 0)
        max = 1;
    return rand() % max;
}


/*
 * roll:
 *	roll a number of dice
 */

int roll(int number, int sides)
{
    register int dtotal = 0;

    while(number--)
	    dtotal += rnd(sides)+1;
    return dtotal;
}