#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char item;
	int l;
	int r;
};

typedef struct node node_t;
static node_t *stack = NULL;
static int top = 0;
static int size;

int init_stack(int sz)
{
	size = sz;
	stack = malloc(size * sizeof(*stack));
	if(!stack)
		return -1;
	else
		return 0;
}

void push(node_t ch)
{
	if(top == size)
	{
		size += size;
		stack = realloc(stack, size * sizeof(*stack));
	}
	stack[top++] = ch;
}

node_t pop(void)
{
	return stack[--top];
}

void destroy(void)
{
	free(stack);
}

int is_empty(void)
{
	return top == 0;
}

int is_full(void)
{
	return top == size;
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
void deep_search(int index)
{
	push(a[index]);
	if(a[index].r != -1)
		deep_search(a[index].r);
	if(a[index].l != -1)
		deep_search(a[index].l);
}


int main(void)
{
	node_t tmp;
	init_stack(100);
	deep_search(0);
	while(!is_empty())
	{
		tmp = pop();
		putchar(tmp.item);
	}
	putchar(10);






	#if 0
	char str[1024];
	int ret , a, b;
	char *p;
	fgets(str, sizeof(str), stdin);
	init_stack(100);
	p = strtok(str, " \n");
	push(atoi(p));
	while((p = strtok(NULL, " \n")))
	{
		switch(*p)
		{
			case '+':
				a = pop();
				b = pop();
				push(b + a);
				break;
			case '-':
				a = pop();
				b = pop();
				push(b - a);
				break;
			case '*':
				a = pop();
				b = pop();
				push(b * a);
				break;
			case '/':
				a = pop();
				b = pop();
				push(b / a);
				break;
			default:
				push(atoi(p));
		}
	}
	printf("ret = %d\n", pop());
	#endif

	return 0;
}
