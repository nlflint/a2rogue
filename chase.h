//
// Created by Nathan Flint on 1/26/20.
//

#ifndef A2ROGUE_CHASE_H
#define A2ROGUE_CHASE_H

#include "rogue.h"

struct room *roomin(coord *cp);
bool diag_ok(coord *sp, coord *ep);
struct monster *find_mons(char y, char x);

#endif //A2ROGUE_CHASE_H
