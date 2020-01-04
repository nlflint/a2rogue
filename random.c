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
