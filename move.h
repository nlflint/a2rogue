//
// Created by Nathan Flint on 1/20/20.
//

#ifndef A2ROGUE_MOVE_H
#define A2ROGUE_MOVE_H

void light(coord *cp);
char show(unsigned char y, unsigned char x);
struct trap *trap_at(unsigned char y, unsigned char x);

#endif //A2ROGUE_MOVE_H
