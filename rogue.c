//
// Created by Nathan Flint on 12/29/19.
//
#include "rogue.h"


struct trap traps[MAXTRAPS];

struct room rooms[MAXROOMS];		/* One for each room -- A level */
struct room *oldrp;			/* Roomin(&oldpos) */
struct linked_list *mlist;		/* List of monsters on the level */


struct monster monsters[MAXMONSTERS];
char MONSTER_COUNT = 0;

struct monster player;			/* The rogue */
struct stats max_stats;			/* The maximum for the player */

#define ___ 1
#define _x {1,1}
struct monster_type monster_types[26] = {
    /* Name		 CARRY	FLAG    str, exp, lvl, amr, hpt, dmg */
    { "giant ant",	 0,	ISMEAN,	{ _x, 10,   2,   3, ___, "1d6" } },
    { "bat",	 0,	0,	{ _x,  1,   1,   3, ___, "1d2" } },
    { "centaur",	 15,	0,	{ _x, 15,   4,   4, ___, "1d6/1d6" } },
    { "dragon",	 100,	ISGREED,{ _x,9000, 10,  -1, ___, "1d8/1d8/3d10" } },
    { "floating eye",0,	0,	{ _x,  5,   1,   9, ___, "0d0" } },
    { "violet fungi",0,	ISMEAN,	{ _x, 85,   8,   3, ___, "000d0" } },
    { "gnome",	 10,	0,	{ _x,  8,   1,   5, ___, "1d6" } },
    { "hobgoblin",	 0,	ISMEAN,	{ _x,  3,   1,   5, ___, "1d8" } },
    { "invisible stalker",0,ISINVIS,{ _x,120,   8,   3, ___, "4d4" } },
    { "jackal",	 0,	ISMEAN,	{ _x,  2,   1,   7, ___, "1d2" } },
    { "kobold",	 0,	ISMEAN,	{ _x,  1,   1,   7, ___, "1d4" } },
    { "leprechaun",	 0,	0,	{ _x, 10,   3,   8, ___, "1d1" } },
    { "mimic",	 30,	0,	{ _x,140,   7,   7, ___, "3d4" } },
    { "nymph",	 100,	0,	{ _x, 40,   3,   9, ___, "0d0" } },
    { "orc",	 15,	ISBLOCK,{ _x,  5,   1,   6, ___, "1d8" } },
    { "purple worm", 70,	0,	{ _x,7000, 15,   6, ___, "2d12/2d4" } },
    { "quasit",	 30,	ISMEAN,	{ _x, 35,   3,   2, ___, "1d2/1d2/1d4" } },
    { "rust monster",0,	ISMEAN,	{ _x, 25,   5,   2, ___, "0d0/0d0" } },
    { "snake",	 0,	ISMEAN,	{ _x,  3,   1,   5, ___, "1d3" } },
    { "troll",	 50,	ISREGEN|ISMEAN,{ _x, 55,   6,   4, ___, "1d8/1d8/2d6" } },
    { "umber hulk",	 40,	ISMEAN,	{ _x,130,   8,   2, ___, "3d4/3d4/2d5" } },
    { "vampire",	 20,	ISREGEN|ISMEAN,{ _x,380,   8,   1, ___, "1d10" } },
    { "wraith",	 0,	0,	{ _x, 55,   5,   4, ___, "1d6" } },
    { "xorn",	 0,	ISMEAN,	{ _x,120,   7,  -2, ___, "1d3/1d3/1d3/4d6" } },
    { "yeti",	 30,	0,	{ _x, 50,   4,   6, ___, "1d6/1d6" } },
    { "zombie",	 0,	ISMEAN,	{ _x,  7,   2,   8, ___, "1d8" } }
};		/* The initial monster states */


struct linked_list *lvl_obj;		/* List of objects on this level */
struct object *cur_weapon;		/* Which weapon he is weilding */
struct object *cur_armor;		/* What a well dresssed rogue wears */
struct object *cur_ring[2];		/* Which rings are being worn */
struct magic_item things[NUMTHINGS];	/* Chances for each type of item */
struct magic_item s_magic[MAXSCROLLS];	/* Names and chances for scrolls */
struct magic_item p_magic[MAXPOTIONS];	/* Names and chances for potions */
struct magic_item r_magic[MAXRINGS];	/* Names and chances for rings */
struct magic_item ws_magic[MAXSTICKS];	/* Names and chances for sticks */


struct WINDOW dungeon_window;
struct WINDOW play_window;
struct WINDOW *cw;
struct WINDOW *stdscr;


struct WINDOW help_window, *hw;
struct WINDOW monster_window, *mw;


char level;				/* What level rogue is on */
int purse;				/* How much gold the rogue has */
unsigned char mpos;				/* Where cursor is on top line */
char ntraps;				/* Number of traps on this level */
int no_move;				/* Number of turns held in place */
int no_command;				/* Number of turns asleep */
int inpack;				/* Number of things in pack */
int max_hp;				/* Player's max hit points */
int total;				/* Total dynamic memory bytes */
int a_chances[MAXARMORS];		/* Probabilities for armor */
int a_class[MAXARMORS];			/* Armor class for various armors */
int lastscore;				/* Score before this turn */
int no_food;				/* Number of levels without food */
int seed;				/* Random number seed */
int count;				/* Number of times to repeat command */
int dnum;				/* Dungeon number */
int fung_hit;				/* Number of time fungi has hit */
int quiet;				/* Number of quiet turns */
int max_level;				/* Deepest player has gone */
int food_left;				/* Amount of food in hero's stomach */
int group;				/* Current group number */
char hungry_state;			/* How hungry is he */

char take;				/* Thing the rogue is taking */
char prbuf[80];				/* Buffer for sprintfs */
//char outbuf[BUFSIZ];			/* Output buffer for stdout */
char runch;				/* Direction player is running */
char *s_names[MAXSCROLLS];		/* Names of the scrolls */
char *p_colors[MAXPOTIONS];		/* Colors of the potions */
char *r_stones[MAXRINGS];		/* Stone settings of the rings */
char *w_names[MAXWEAPONS];		/* Names of the various weapons */
char *a_names[MAXARMORS];		/* Names of armor types */
char *ws_made[MAXSTICKS];		/* What sticks are made of */
char *release;				/* Release number of rogue */
char whoami[80];			/* Name of player */
char fruit[80];				/* Favorite fruit */
char huh[80];				/* The last message printed */
char *s_guess[MAXSCROLLS];		/* Players guess at what scroll is */
char *p_guess[MAXPOTIONS];		/* Players guess at what potion is */
char *r_guess[MAXRINGS];		/* Players guess at what ring is */
char *ws_guess[MAXSTICKS];		/* Players guess at what wand is */
char *ws_type[MAXSTICKS];		/* Is it a wand or a staff */
char file_name[80];			/* Save file name */
char home[80];				/* User's home directory */

bool running = FALSE;				/* True if player is running */
bool playing = TRUE;				/* True until he quits */
bool wizard = FALSE;				/* True if allows wizard commands */
bool after;				/* True if we want after daemons */
bool notify = TRUE;				/* True if player wants to know */
bool fight_flush;			/* True if toilet input */
bool terse;				/* True if we should be short */
bool door_stop;				/* Stop running when we pass a door */
bool jump;				/* Show running as series of jumps */
bool slow_invent;			/* Inventory one line at a time */
bool firstmove;				/* First move after setting door_stop */
bool waswizard;				/* Was a wizard sometime */
bool askme;				/* Ask about unidentified things */
bool s_know[MAXSCROLLS];		/* Does he know what a scroll does */
bool p_know[MAXPOTIONS];		/* Does he know what a potion does */
bool r_know[MAXRINGS];			/* Does he know what a ring does */
bool ws_know[MAXSTICKS];		/* Does he know what a stick does */
bool amulet;				/* He found the amulet */
bool in_shell;				/* True if executing a shell */

coord oldpos;				/* Position before last look() call */
coord delta;				/* Change indicated to get_dir() */
