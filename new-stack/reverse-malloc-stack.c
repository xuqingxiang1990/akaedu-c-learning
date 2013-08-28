#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int top = 0;
static int *stack = NULL;
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

void push(char ch)
{
	if(top == size)
	{
		size += size;
		stack = realloc(stack, size * sizeof(*stack));
	}

	stack[top++] = ch;	
}

int pop(void)
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


int main(void)
{
	char str[1024];
	char *p;
	int ret;
	int a, b;
	init_stack(100);
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	p = strtok(str, " ");
	push(atoi(p));
	while((p = strtok(NULL, " ")))
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



	
	#if 0
	char ch;
	init_stack(5);
	while((ch = getchar()) != '\n')
		push(ch);
	while(!is_empty())
		putchar(pop());
	destroy_stack();
	putchar(10);
	#endif

	return 0;
}
