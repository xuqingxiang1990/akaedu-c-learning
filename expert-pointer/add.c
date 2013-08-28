#include <stdio.h>


int add(int a, int b)
{
	static int t = 0;
	const int c = 100;
	printf("%d\n", c);
	*(int *)&c = 200;
	printf("%d\n", c);

	t = a + b;
	return t;
}

int main(void)
{
	printf(" add1 = %d add2 = %d\n", add(3, 1), add(3, 4));

	return 0;
}
