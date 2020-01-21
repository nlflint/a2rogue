/*
 * Various input/output functions
 *
 * @(#)io.c	3.10 (Berkeley) 6/15/81
 */

#include "curses.h"
#include "io.h"
#include "rogue.h"
#include <stdio.h>


/*
 * msg:
 *	Display a message at the top of the screen.
 */

//static char msgbuf[BUFSIZ];
//static int newpos = 0;

/*VARARGS1*/
//msg(fmt, args)
//char *fmt;
//int args;
//{
//    /*
//     * if the string is "", just clear the line
//     */
//    if (*fmt == '\0')
//    {
//	wmove(cw, 0, 0);
//	wclrtoeol(cw);
//	mpos = 0;
//	return;
//    }
//    /*
//     * otherwise add to the message and flush it out
//     */
//    doadd(fmt, &args);
//    endmsg();
//}

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
//endmsg()
//{
//    strcpy(huh, msgbuf);
//    if (mpos)
//    {
//	wmove(cw, 0, mpos);
//	waddstr(cw, "--More--");
//	draw(cw);
//	wait_for(' ');
//    }
//    mvwaddstr(cw, 0, 0, msgbuf);
//    wclrtoeol(cw);
//    mpos = newpos;
//    newpos = 0;
//    draw(cw);
//}
//
//doadd(fmt, args)
//char *fmt;
//int **args;
//{
//    static FILE junk;
//
//    /*
//     * Do the printf into buf
//     */
//    junk._flag = _IOWRT + _IOSTRG;
//    junk._ptr = &msgbuf[newpos];
//    junk._cnt = 32767;
//    _doprnt(fmt, args, &junk);
//    putc('\0', &junk);
//    newpos = strlen(msgbuf);
//}

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
            get_hunger_state());
}

const char *get_hunger_state() {

}

/*
 * wait_for
 *	Sit around until the guy types the right key
 */

//wait_for(ch)
//register char ch;
//{
//    register char c;
//
//    if (ch == '\n')
//        while ((c = readchar()) != '\n' && c != '\r')
//	    continue;
//    else
//        while (readchar() != ch)
//	    continue;
//}

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
