#include <stdio.h>
#include <stdlib.h>

static char *queue;
static int t, h;
static int size, qc;

void init_queue(int sz)
{
	size = sz;
	queue = malloc(size * sizeof(*queue));
	h = t = qc = 0;
	
}

void enter_queue(char item)
{
	queue[t++] = item;
	t %= size;
	qc++;
}

char out_queue(void)
{
	char ch;
	ch = queue[h++];
	h %= size;
	qc--;
	return ch;
}

int is_full(void)
{
	return qc == size;
}

int is_empty(void)
{
	return qc == 0;	
}

void destroy(void)
{
	free(queue);
}

int main(void)
{
	char ch;
	init_queue(10);
	while((ch = getchar()) != '\n' && !is_full())
		enter_queue(ch);
	while(!is_empty())
		putchar(out_queue());
	putchar(10);
	destroy();
		

	return 0;
}
