#include <stdio.h>

const int A = 10;
int a = 20;
static int b = 30;
int c;

int main(void)
{
	static int e = 40;
	static int a = 20;
//	char b[] = "hello word";
	register int f = 50;

	printf("hello world %d\n", c);
	printf(" &a = %p\n", &a);
	printf(" &b = %p\n", &b);
	printf(" &c = %p\n", &c);
	printf(" &A = %p\n", &A);
	printf(" &e = %p\n", &e);

	return 0;
}
