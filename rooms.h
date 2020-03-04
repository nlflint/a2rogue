//
// Created by Nathan Flint on 12/29/19.
//

#ifndef A2ROGUE_ROOMS_H
#define A2ROGUE_ROOMS_H

void do_rooms(void);
void rnd_pos(struct room *rp, coord *cp);
void draw_room(struct room *rp);
void horiz(unsigned char cnt);
void vert(char cnt);

#endif //A2ROGUE_ROOMS_H

