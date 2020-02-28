void show_window(struct WINDOW *window) {
    clrscr();
    cputsxy(0, 0, window->data[0]);
}

; Take a pointer to a WINDOW via fast call, and copies to the screen

        .export         show_window_fast

        .include		"zeropage.inc"

        .macpack        generic

show_window_fast:
		bit LOWSCR ;set text store to main memory (odd columns)

		sta ptr1 ;data backup pointer
		sta ptr2 ;data pointer
        stx ptr1 + 1
        stx ptr2 + 1

		;set odds offset
		inc ptr2
		bne :+
		sta ptr2 + 1
		
copy:
		lda $00
		sta ptr3 ;screen pointer
		lda $40
		sta ptr + 1

		bit LOWSCR


        rts
