#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int item;
	int l;
	int r;
};

static int top = 0;
static struct node *stack = NULL;
static int sz;
static int size;

int init_stack(int sz)
{
	size = sz;	
	stack = malloc(sz * sizeof(*stack));
	if(!stack)
		return -1;
	return 0;
}

void push(struct node ch)
{
	if(top == size)
	{
		size += size;
		stack = realloc(stack, size * sizeof(*stack));
	}

	stack[top++] = ch;	
}

struct node pop(void)
{
	return stack[--top];	
}


int is_empty()
{
	return top == 0;
}

int is_full(void)
{
	return top == size;
}

void destroy_stack(void)
{
	free(stack);
}

struct node a[] = {{'a', 1, 2},{'b', 3, 4}, {'c', 5, 6}, {'d', -1, -1}, {'e', -1, -1}, {'f', -1, -1}, {'g', -1, -1}};

void de_traver(int index)
{
	push(a[index]);
	if(a[index].r != -1)
		de_traver(a[index].r);
	if(a[index].l != -1)
		de_traver(a[index].l);
}

int main(void)
{
	
	struct node t;
	init_stack(20);
	de_traver(0);
	while(!is_empty())
	{
		t = pop();
		putchar(t.item);
	}

	putchar(10);

	return 0;
}
