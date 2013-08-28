#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
static struct node *stack = NULL;
static int top;
static int size;
void push(struct node iterm)
{
	if (top == size) {
		size += size;
		stack = realloc(stack, size * sizeof(*stack));
	}
	stack[top++] = iterm;
}
struct node pop(void)
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
int init_stack(int sz)
{
	size = sz;
	stack = malloc(size * sizeof(*stack));
	if (!stack) return -1;
	return 0;
}
void destroy_stack(void)
{
	free(stack);
}
#if 0
int main(void)
{
	char ch;
	init_stack(5);
	while ((ch = getchar()) != '\n')
		push(ch);
	while (!is_empty())
		putchar(pop());
	putchar('\n');
	destroy_stack();
	return 0;
}
#endif
