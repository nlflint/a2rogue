a2rogue: main.c
	cl65 -v -vm -t apple2enh main.c new_level.c rooms.c random.c curses.c rogue.c -o main
	cp ./makelib/prodos_template.dsk a2rogue.dsk
	java -jar makelib/AppleCommander.jar -as a2rogue.dsk main < main