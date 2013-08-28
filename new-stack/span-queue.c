#include <stdio.h>
#include <stdlib.h>

struct node {
	int item;
	int l;
	int r;
};

typedef struct node node_t;

static node_t *queue;
static int t, h;
static int size, qc;

void init_queue(int sz)
{
	size = sz;
	queue = malloc(size * sizeof(*queue));
	h = t = qc = 0;
	
}

void enter_queue(node_t item)
{
	queue[t++] = item;
	t %= size;
	qc++;
}

node_t out_queue(void)
{
	node_t ch;
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
node_t a[] = {  {'a', 1, 2},
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
	char sort[32];
	init_queue(20);
	bfs_travel(0, sort);

	printf("%s\n", sort);
	destroy();
	return 0;
}
