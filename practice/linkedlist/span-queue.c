#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5


struct point {
	int row;
	int col;
	int pre;
};

typedef struct point point_t;

point_t queue[512];

int head = 0;
int tail = 0;


void enqueue(point_t p)
{
	queue[tail++] = p;
}

point_t dequeue(void)
{
	return queue[head++];
}

int is_empty(void)
{
	return head == tail;
}

int maze[MAX_ROW][MAX_COL] = {
				0, 1, 0, 0, 0,
				0, 1, 0, 1, 0,
				0, 0, 0, 0, 0,
				0, 1, 1, 1, 0,
				0, 0, 0, 1, 0,
};

void print_queue(void)
{
	int i, j;
	for(i = 0; i < MAX_ROW; i++)
	{
		for(j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar(10);
	}
	printf("*************\n");
}

void visit(int row, int col)
{
	point_t visit_t = {row, col, head - 1};
	maze[row][col] = 2;
	enqueue(visit_t);
}

int main(void)
{
	point_t p = {0, 0, -1};
	maze[p.row][p.col] = 2;
	enqueue(p);
	while(!is_empty())
	{
		p = dequeue();	
		if(p.row == MAX_ROW && p.col == MAX_COL)
			break;
		if(p.col + 1 < MAX_COL && maze[p.row][p.col + 1])
			visit(p.row, p.col + 1);
		if(p.row + 1 < MAX_ROW && maze[p.row + 1][p.col])
			visit(p.row + 1, p.col);
		if(p.col - 1 >= 0  && maze[p.row][p.col - 1])
			visit(p.row, p.col - 1);
		if(p.row - 1 >= 0  && maze[p.row - 1][p.col])
			visit(p.row - 1, p.col);
		print_queue();
	}
	if(p.row == MAX_ROW && p.col == MAX_COL)
	{
		printf("(%d, %d)\n", p.row, p.col);
		while(p.pre != -1)
		{
			p = queue[p.pre];
			printf("(%d, %d)\n", p.row, p.col);
		}
	}
	else
		printf("NO path\n");

	return 0;
}
