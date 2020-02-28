//
// Created by Nathan Flint on 12/29/19.
//
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "curses.h"
#include "rogue.h"

#pragma code-name(push, "LC")

void wclear(struct WINDOW *window) {
    unsigned char x, y;
    window->y = window->x = 0;
    for(y = 0; y < LINES; y++ ) {
        sprintf(window->data[y], "                                                                                ");
//        for(x = 0; x < COLS; x++ ) {
//            window->data[y][x] = ' ';
//        }
    }
    window->end = 0;

    if (window == cw) {
        clrscr();
    }
}

void wmove(struct WINDOW *window, unsigned char y, unsigned char x) {
    window->x = x;
    window->y = y;

    if (window == cw)
        gotoxy(x, y);

}

//put char, then move forward
void waddch(struct WINDOW *window, char character) {
    unsigned char
        x = window->x,
        y = window->y;

    if (window == cw)
        putchar(character);

    window->data[y][x] = character;
    (window->x)++;
}

// get char at current x, y
char winch(struct WINDOW *window) {
    unsigned char x, y;
    getyx(window, y, x);
    return window->data[y][x];
}

char mvwinch(struct WINDOW *window, unsigned char y, unsigned char x) {
    wmove(window, y, x);
    return winch(window);
}

void mvwaddch(struct WINDOW *window, unsigned char y, unsigned char x, char ch) {
    wmove(window, y, x);
    waddch(window, ch);
}

void show_window(struct WINDOW *window) {
    clrscr();
    cputsxy(0, 0, window->data[0]);
}

void wclrtoeol(struct WINDOW *window) {
    char
        //*row = window->data[window->y],
        x = wherex();

    while (x++ < COLS)
    {
        cputc(' ');
        //mvwaddch(cw, y, x++, ' ');
        //row[x++] = ' ';
    }

//    if(window == cw) {
//        gotoxy(x,y);
//        clrtoeol();
//    }
}

void waddstr(struct WINDOW *window, char *string) {
    unsigned char x = window->x, y = window->y;

    strcpy(&window->data[y][x], string);

    if (window == cw){
        cputsxy(x, y, string);
    }
}

char buffer[81];

void debug_num(char *description, int number) {
    gotoxy(0,0);
    cclear(80);
    sprintf(buffer, "%s: %d", description, number);
    cputsxy(0, 0, buffer);
    cgetc();
}

void debug_coord(char *description, coord *coor) {
    gotoxy(0,0);
    cclear(80);
    sprintf(buffer, "%s: x:%d, y:%d", description, coor->x, coor->y);
    cputsxy(0, 0, buffer);
    cgetc();
}

void debug_char(char *description, char ch) {
    sprintf(buffer, "%s: %c", description, ch);
    cputsxy(0, 0, buffer);
    cgetc();
}

#pragma code-name(pop)