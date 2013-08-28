#include <stdio.h>
#include "queue.h"


node_t *queue = NULL;
int head = 0;
int tail = 0;
int size;
int qc;
node_t a[] = {
				{'a', 1, 2},
				{'b', 3, 4},
				{'c', 5, 6},
				{'d', -1, -1},
				{'e', -1, -1},
				{'f', -1, -1},
				{'g', -1, -1}
			};
int i = 0;

void bfs_travel(int index, char sort[])
{
	node_t t;
	enter_queue(a[index]);
	while(!is_empty())
	{
		t = out_queue();
		sort[i++] = t.item;
		if(t.l != -1)
			enter_queue(a[t.l]);
		if(t.r != -1)
			enter_queue(a[t.r]);
	}
	sort[i] = '\0';
}


int main(void)
{
	char ch;
	char sort[32];
	init_queue(20);
	bfs_travel(0, sort);
	printf("%s\n", sort);
	destory();	


	return 0;
}
