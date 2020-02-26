//
// Created by Nathan Flint on 12/29/19.
//

#ifndef A2ROGUE_IO_H
#define A2ROGUE_IO_H

#include <stdarg.h>

void doadd(const char* fmt, va_list varargs);
void status(void);
const char *get_hunger_state(void);
void msg(const char* fmt, ...);
void endmsg(void);
void wait_for(char ch);

#endif //A2ROGUE_IO_H
