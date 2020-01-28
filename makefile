
a2rogue.dsk : main
	cp ./makelib/prodos_template.dsk a2rogue.dsk
	java -jar makelib/AppleCommander.jar -as a2rogue.dsk main < main

main : main.c new_level.c rooms.c random.c curses.c rogue.c passages.c \
		io.c rogue.h new_level.h curses.h random.h rooms.h passages.h \
		io.h move.h move.c chase.h chase.c
	cl65 -m blah.txt -v -vm -t apple2enh main.c new_level.c rooms.c random.c curses.c rogue.c move.c passages.c io.c chase.c -o main
