#include <stdio.h>
#include <curses.h>

#define LEFTEDGE  10
#define RIFHTEDGE 30
#define ROW       10

int main(void)
{
	char *message = "hello";
	char *blank = " ";
	int dir = 1;
	int pos = LEFTEDGE;

	initscr();
	clear();
	while(1)
	{
		move(ROW, pos);
		addstr(message);
		refresh();
		sleep(1);
		move(ROW, pos);
		addstr(blank);
		pos += dir;
		if(pos >= RIFHTEDGE)
			dir = -1;
		if(pos <= LEFTEDGE)
			dir = 1;
	}
	return 0;
}
