/* 3/5/81 (Berkeley) @(#)curses.h	1.4 */
//# ifndef WINDOW

//# include	<stdio.h>
//# include	<sgtty.h>
#ifndef A2ROGUE_CURSES_H
#define A2ROGUE_CURSES_H

#include "rogue.h"

# define	bool	char
//# define	reg	register

#define	ERR	(0)
#define	OK	(1)
#define	move(y, x) wmove(stdscr, y, x)

extern char debug_row;

//move STD cursor to x,y
void wmove(struct WINDOW *window, unsigned char y, unsigned char x);
void waddch(struct WINDOW *window, char character);
char winch(struct WINDOW *window);
void wclear(struct WINDOW *window);
char mvwinch(struct WINDOW *window, unsigned char y, unsigned char x);
void mvwaddch(struct WINDOW *window, unsigned char y, unsigned char x, char ch);
void show_window(struct WINDOW *window);
void apply_status(void);
void debug_num(char *description, int number);
void debug_char(char *description, char ch);
void debug_coord(char *description, coord *coor);
void wclrtoeol(struct WINDOW *window);
void waddstr(struct WINDOW *window, char *string);


//# define	_SUBWIN		01
//# define	_ENDLINE	02
//# define	_FULLWIN	04
//# define	_SCROLLWIN	010
//# define	_FLUSH		020
//# define	_STANDOUT	0200
//# define	_NOCHANGE	-1

//# define	_puts(s)	tputs(s, 0, _putchar);

//typedef	struct sgttyb	SGTTY;

/*
 * Capabilities from termcap
 */

//extern bool     AM, BS, CA, DA, DB, EO, GT, HZ, IN, MI, MS, NC, OS, UL,
//		XN;
//extern char     *AL, *BC, *BT, *CD, *CE, *CL, *CM, *DC, *DL, *DM, *DO,
//		*ED, *EI, *HO, *IC, *IM, *IP, *LL, *MA, *ND, *SE, *SF,
//		*SO, *SR, *TA, *TE, *TI, *UC, *UE, *UP, *US, *VB, *VE,
//		*VS, PC;

/*
 * From the tty modes...
 */

//extern bool	NONL, UPPERCASE, normtty, _pfast;

//struct _win_st {
//	short	_cury, _curx;
//	short	_maxy, _maxx;
//	short	_begy, _begx;
//	short	_flags;
//	bool	_clear;
//	bool	_leave;
//	bool	_scroll;
//	char	**_y;
//	short	*_firstch;
//	short	*_lastch;
//};

//# define	WINDOW	struct _win_st

//extern bool	My_term, _echoit, _rawmode, _endwin;

//extern char	*Def_term, ttytype[];

//extern int	LINES, COLS, _tty_ch, _res_flg;

//extern SGTTY	_tty;

//extern WINDOW	*stdscr, *curscr;

/*
 *	Define VOID to stop lint from generating "null effect"
 * comments.
 */
//# ifdef lint
//int	__void__;
//# define	VOID(x)	(__void__ = (int) (x))
//# else
//# define	VOID(x)	(x)
//# endif

/*
 * psuedo functions for standard screen
 */
#define	addch(ch)	waddch(stdscr, ch)
//# define	getch()		VOID(wgetch(stdscr))
//# define	addstr(str)	VOID(waddstr(stdscr, str))
//# define	getstr(str)	VOID(wgetstr(stdscr, str))
//# define	move(y, x)	VOID(wmove(stdscr, y, x))
//# define	clear()		VOID(wclear(stdscr))
//# define	erase()		VOID(werase(stdscr))
//# define	clrtobot()	VOID(wclrtobot(stdscr))
#define	clrtoeol()	wclrtoeol(stdscr)
//# define	insertln()	VOID(winsertln(stdscr))
//# define	deleteln()	VOID(wdeleteln(stdscr))
//# define	refresh()	VOID(wrefresh(stdscr))
//# define	inch()		VOID(winch(stdscr))
//# define	standout()	VOID(wstandout(stdscr))
//# define	standend()	VOID(wstandend(stdscr))

/*
 * mv functions
 */
//#define	mvwaddch(win,y,x,ch)	(wmove(win,y,x)==ERR?ERR:waddch(win,ch))
//#define	mvwgetch(win,y,x)	VOID(wmove(win,y,x)==ERR?ERR:wgetch(win))
#define	mvwaddstr(win,y,x,str)	wmove(win,y,x);waddstr(win,str)
//#define	mvwgetstr(win,y,x)	VOID(wmove(win,y,x)==ERR?ERR:wgetstr(win))
//#define	mvwinch(win,y,x)	(wmove(win,y,x) == ERR ? ERR : winch(win))
#define	mvaddch(y,x,ch)		mvwaddch(stdscr,y,x,ch)
//#define	mvgetch(y,x)		mvwgetch(stdscr,y,x)
//#define	mvaddstr(y,x,str)	mvwaddstr(stdscr,y,x,str)
//#define	mvgetstr(y,x)		mvwgetstr(stdscr,y,x)
#define	mvinch(y,x)		mvwinch(stdscr,y,x)

/*
 * psuedo functions
 */

//#define	clearok(win,bf)	 (win->_clear = bf)
//#define	leaveok(win,bf)	 (win->_leave = bf)
//#define	scrollok(win,bf) (win->_scroll = bf)
//#define flushok(win,bf)	 (bf ? (win->_flags |= _FLUSH):(win->_flags &= ~_FLUSH))
#define	getyx(win,y_var,x_var)	 y_var = win->y, x_var = win->x
//#define	winch(win)	 (win->_y[win->_cury][win->_curx])
//
//#define raw()	 (_tty.sg_flags|=RAW, _pfast=_rawmode=TRUE, stty(_tty_ch,&_tty))
//#define noraw()	 (_tty.sg_flags&=~RAW,_rawmode=FALSE,_pfast=!(_tty.sg_flags&CRMOD),stty(_tty_ch,&_tty))
//#define crmode() (_tty.sg_flags |= CBREAK, _rawmode = TRUE, stty(_tty_ch,&_tty))
//#define nocrmode() (_tty.sg_flags &= ~CBREAK,_rawmode=FALSE,stty(_tty_ch,&_tty))
//#define echo()	 (_tty.sg_flags |= ECHO, _echoit = TRUE, stty(_tty_ch, &_tty))
//#define noecho() (_tty.sg_flags &= ~ECHO, _echoit = FALSE, stty(_tty_ch, &_tty))
//#define nl()	 (_tty.sg_flags |= CRMOD,_pfast = _rawmode,stty(_tty_ch, &_tty))
//#define nonl()	 (_tty.sg_flags &= ~CRMOD, _pfast = TRUE, stty(_tty_ch, &_tty))
//#define	savetty() (gtty(_tty_ch, &_tty), _res_flg = _tty.sg_flags)
//#define	resetty() (_tty.sg_flags = _res_flg, stty(_tty_ch, &_tty))
//
//WINDOW	*initscr(), *newwin(), *subwin();
//char	*longname();
//
//# endif

#endif
