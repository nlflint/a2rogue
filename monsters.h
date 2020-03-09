//
// Created by nathan on 3/3/20.
//

#ifndef A2ROGUE_MONSTERS_H
#define A2ROGUE_MONSTERS_H

struct monster *new_monster(char type, coord *cp);
char randmonster(bool wander);
struct monster *wake_monster(char y, char x);
void clear_monsters(void);

#endif //A2ROGUE_MONSTERS_H
