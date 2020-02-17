/*
 * Various input/output functions
 *
 * @(#)io.c	3.10 (Berkeley) 6/15/81
 */

#include "curses.h"
#include "io.h"
#include "rogue.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>


/*
 * msg:
 *	Display a message at the top of the screen.
 */

static char msgbuf[COLS+1];
static int next_pos = 0;

/*VARARGS1*/
void msg(char *fmt, char count, ...)
{
    va_list varargs;
    /*
     * if the string is "", just clear the line
     */
    if (*fmt == '\0')
    {
        wmove(cw, 0, 0);
        wclrtoeol(cw);
        mpos = 0;
        return;
    }
    /*
     * otherwise add to the message and flush it out
     */
    va_start(varargs, count);
    doadd(fmt, varargs);
    endmsg();
    va_end(varargs);
}

/*
 * add things to the current message
 */
//addmsg(fmt, args)
//char *fmt;
//int args;
//{
//    doadd(fmt, &args);
//}

/*
 * Display a new msg (giving him a chance to see the previous one if it
 * is up there with the --More--)
 */
void endmsg(void)
{
    strcpy(huh, msgbuf);

    if (mpos)
    {
        wmove(cw, 0, mpos);
        waddstr(cw, "--More--");
        //draw(cw);
        wait_for(' ');
    }

    mvwaddstr(cw, 0, 0, msgbuf);
    mvwinch(cw, 0, next_pos);

    wclrtoeol(cw);
    mpos = next_pos;
    next_pos = 0;
    //draw(cw);
}

void doadd(char *fmt, va_list varargs)
{
//    debug_char("do add msgbuf[0]", msgbuf[0]);
//    debug_char("do add msgbuf[1]", msgbuf[1]);
//    debug_char("do add msgbuf[2]", msgbuf[2]);
//    debug_char("do add msgbuf[3]", msgbuf[3]);
//    debug_char("do add msgbuf[4]", msgbuf[4]);
//    debug_char("do add msgbuf[5]", msgbuf[5]);
//    debug_char("do add msgbuf[6]", msgbuf[6]);
//    debug_char("do add msgbuf[7]", msgbuf[7]);
//    debug_char("do add msgbuf[8]", msgbuf[8]);
//    debug_char("do add msgbuf[9]", msgbuf[9]);
//    debug_char("do add msgbuf[10]", msgbuf[10]);
//    debug_char("do add msgbuf[11]", msgbuf[11]);
    vsprintf(&msgbuf[next_pos], fmt, varargs);

//    debug_char("msgbuf[0]", msgbuf[0]);
//    debug_char("msgbuf[1]", msgbuf[1]);
//    debug_char("msgbuf[2]", msgbuf[2]);
//    debug_char("msgbuf[3]", msgbuf[3]);
//    debug_char("msgbuf[4]", msgbuf[4]);
//    debug_char("msgbuf[5]", msgbuf[5]);
//    debug_char("msgbuf[6]", msgbuf[6]);
//    debug_char("msgbuf[7]", msgbuf[7]);
//    debug_char("msgbuf[8]", msgbuf[8]);
//    debug_char("msgbuf[9]", msgbuf[9]);
//    debug_char("msgbuf[10]", msgbuf[10]);
//    debug_char("msgbuf[11]", msgbuf[11]);

    next_pos = strlen(msgbuf);
//    debug_num("next_pos", next_pos);
//    static FILE junk;

    /*
     * Do the printf into buf
     */
//    junk._flag = _IOWRT + _IOSTRG;
//    junk._ptr = &msgbuf[newpos];
//    junk._cnt = 32767;
//    _doprnt(fmt, args, &junk);
//    putc('\0', &junk);
//    newpos = strlen(msgbuf);

}

/*
 * step_ok:
 *	returns true if it is ok to step on ch
 */

//step_ok(ch)
//{
//    switch (ch)
//    {
//	case ' ':
//	case '|':
//	case '-':
//	case SECRETDOOR:
//	    return FALSE;
//	default:
//	    return (!isalpha(ch));
//    }
//}

/*
 * readchar:
 *	flushes stdout so that screen is up to date and then returns
 *	getchar.
 */

//readchar()
//{
//    char c;
//
//    fflush(stdout);
//    while (read(0, &c, 1) < 0)
//	continue;
//    return c;
//}

/*
 * unctrl:
 *	Print a readable version of a certain character
 */

//char *
//unctrl(ch)
//char ch;
//{
//    extern char *_unctrl[];		/* Defined in curses library */
//
//    return _unctrl[ch&0177];
//}

/*
 * status:
 *	Display the important stats line.  Keep the cursor where it was.
 */

void status(void)
{
    char *hungry_description, *status_bar;

    switch (hungry_state)
    {
        case 1: hungry_description = "  Hungry";
        case 2: hungry_description = "  Weak";
        case 3: hungry_description = "  Fainting";
        default: hungry_description = "";
    }

    status_bar = play_window.data[23];
    sprintf(status_bar, "Level: %d  Gold: %-5d  Hp: %d(%d)  Str: %-2d/%d Ac: %-2d  Exp: %d/%ld %s",
            level,
            purse,
            pstats.s_hpt,
            max_hp,
            pstats.s_str.st_str,
            pstats.s_str.st_add,
            cur_armor != NULL ? cur_armor->o_ac : pstats.s_arm,
            pstats.s_lvl,
            pstats.s_exp,
            /*get_hunger_state()*/ "Hungry");
}

//const char *get_hunger_state() {
//
//}

/*
 * wait_for
 *	Sit around until the guy types the right key
 */

void wait_for(char ch)
{
    register char c;

//    if (ch == '\n')
//        while ((c = cgetc()) != '\n' && c != '\r')
//	    continue;
//    else
        while (cgetc() != ch)
	        continue;
}

/*
 * show_win:
 *	function used to display a window and wait before returning
 */

//show_win(scr, message)
//register WINDOW *scr;
//char *message;
//{
//    mvwaddstr(scr, 0, 0, message);
//    touchwin(scr);
//    wmove(scr, hero.y, hero.x);
//    draw(scr);
//    wait_for(' ');
//    clearok(cw, TRUE);
//    touchwin(cw);
//}
