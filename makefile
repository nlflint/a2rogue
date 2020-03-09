
a2rogue.dsk : main
	cp ./makelib/prodos_template.dsk a2rogue.dsk
	java -jar makelib/AppleCommander.jar -as a2rogue.dsk main < main

main : main.c new_level.c rooms.c random.c curses.c rogue.c passages.c \
		io.c rogue.h new_level.h curses.h random.h rooms.h passages.h \
		io.h move.h move.c chase.h chase.c init.c command.h command.c \
		misc.h misc.c a2rogue.cfg pack.c pack.h things.c things.h \
		monsters.c monsters.h fight.c fight.h
	cl65 -v -vm -m mapfile.txt -t apple2enh -C a2rogue.cfg main.c new_level.c rooms.c random.c curses.c \
		rogue.c move.c passages.c io.c chase.c init.c command.c misc.c \
		pack.c things.c monsters.c fight.c \
		-o main