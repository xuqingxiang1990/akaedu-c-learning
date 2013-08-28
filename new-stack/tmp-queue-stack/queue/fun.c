#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(int sz)
{
	size = sz;
	qc = tail = head = 0;
	queue = malloc(size * sizeof(*queue));
}

void enter_queue(node_t ch)
{
	queue[tail++] = ch;
	tail %= size;
	qc++;
}

node_t out_queue(void)
{
	node_t ch;
	ch = queue[head++];
	head %= size;
	qc--;
	return ch;
}

int is_empty(void)
{
	return qc == 0;
}

int is_full(void)
{
	return qc == size;
}

void destory(void)
{
	free(queue);
}
