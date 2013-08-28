#include <stdio.h>

int main(void)
{
	int a[10];
	int *p;
	int (*p2)[10];

	p = a;
	p2 = &a;

	printf("a = %p\n", a);
	printf("&a = %p\n", &a);

	printf("a + 1 = %p\n", p + 1);
	printf("&a + 1 = %p\n", p2 + 1);

	return 0;
}
