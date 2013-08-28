#include <stdio.h>
#include "stack.h"
/*
struct node {
	char iterm;
	int l;
	int r;
};
*/
struct node a[] = {{'a',1,2}, {'b',3,4}, {'c',5,6},{'d',-1,-1},{'e',-1,-1},{'f',-1,-1},{'g',-1,-1}};

void dep_travel(int index)
{
	push(a[index]);
	if (a[index].r != -1)	dep_travel(a[index].r);
	if (a[index].l != -1)	dep_travel(a[index].l);
}
int main(void)
{
	struct node t;
	init_stack(20);
	dep_travel(0);
	while (!is_empty()) {
		t = pop();
		putchar(t.iterm);
	}
		putchar('\n');
	return 0;
}
