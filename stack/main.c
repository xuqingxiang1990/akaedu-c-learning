#include <stdio.h>
#include "stack.h"

int main(void)
{
	push('a');
	push('b');
	push('c');
	while(!is_empty())
		putchar(pop());
	putchar(10);

	return 0;
}
