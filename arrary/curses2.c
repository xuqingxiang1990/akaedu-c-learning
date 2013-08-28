#include <stdio.h>
#include <curses.h>

int main(void)
{
	int i;

	initscr();
	clear();
	for(i = 0; i < LINES; i++)
	{
		move(i, i+1);
		if(i % 2 == 1)
			standout();
		addstr("hello, word");
		if(i % 2 == 1)
			standend();
		refresh();
		sleep(1);
		move(i, i + 1);
		addstr("       ");

	}
	endwin();

	return 0;
}
