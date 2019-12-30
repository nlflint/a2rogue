//
// Created by Nathan Flint on 12/29/19.
//
#include <conio.h>
#include "curses.h"

void clear(void) {
    clrscr();
}

void move(char y, char x) {
    gotoxy(x, y);
}

char getx(void) {
    return wherex();
}

char gety(void) {
    return wherey();
}

void addch(char character) {
    cputc(character);
}