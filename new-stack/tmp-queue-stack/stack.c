#include <stdio.h>
#include "stack.h"


node_t *stack = NULL;

int top = 0;
int size;

node_t a[] = {
				{'a', 1, 2},
				{'b', 3, 4},
				{'c', 5, 6},
				{'d', -1, -1},
				{'e', -1, -1},
				{'f', -1, -1},
				{'g', -1, -1}
		   	};
void dep_trave(int index)
{
	push(a[index]);
	if(a[index].r != -1)
		dep_trave(a[index].r);
	if(a[index].l != -1)
		dep_trave(a[index].l);
	
}


int main(void)
{
	node_t tmp;
	init_stack(20);
	dep_trave(0);
	while(!is_empty())
	{
		tmp = pop();
		putchar(tmp.item);
	}

	putchar(10);
	destory(stack);


	return 0;	
}
