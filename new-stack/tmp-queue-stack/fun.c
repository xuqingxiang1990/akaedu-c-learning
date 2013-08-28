#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(int sz)
{
	size = sz;
	stack = malloc(size * sizeof(*stack));
}

void push(node_t item)
{
	if(top == size)
	{
		size += size;
		stack = malloc(size * sizeof(*stack));	
	}

	stack[top++] = item;
}

node_t pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

int is_full(void)
{
	return top == size;
}
void destory()
{
	free(stack);
}
