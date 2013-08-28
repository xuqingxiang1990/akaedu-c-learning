#include <stdio.h>
#include <curses.h>

int main(void)
{
	initscr();

	clear();
	move(10, 20);
	addstr("hello, word");
	move(LINES-1, 0);
	refresh();
	getch();
	endwin();

	return 0;
}
