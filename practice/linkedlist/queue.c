#include <stdio.h>
#include <stdlib.h>

struct node {
	char item;
	int l;
	int r;
};

typedef struct node node_t;

int head = 0;
int tail = 0;
int qc = 0;
int size;
node_t *queue = NULL;




void init_queue(int sz)
{
	size = sz;
	queue = malloc(size * sizeof(*queue));
	head = tail = qc = 0;
}

void enter_queue(node_t ch)
{
	if(qc == size)
	{
		size += size;
		queue = realloc(queue, size * sizeof(*queue));
	}
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

void destroy(void)
{
	free(queue);
}

int is_empty(void)
{
	return qc == 0;
}

int is_full(void)
{
	return qc == size;
}

node_t a[] = {
				{'a', 1, 2},
				{'b', 3, 4},
				{'c', 5, 6},
				{'d', -1, -1},
				{'e', -1, -1},
				{'f', -1, -1},
				{'g', -1, -1},
			};

int i = 0;
void span_queue(int index, char sort[])
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
}


int main(void)
{
	char sort[100];
	char ch;
	init_queue(100);
	span_queue(0, sort);
	printf("%s\n", sort);


	return 0;	
}
