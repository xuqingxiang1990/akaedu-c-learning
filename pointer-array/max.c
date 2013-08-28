#include <stdio.h>

#define MAX(x,y) ((x)>(y))?(x):(y)
#define PINT_INT(x) printf(#x "=%d\n",x)
#define MK_ID(n) i##n
int main(void)
{
	int a, b;
	int MK_ID(1), MK_ID(2), MK_ID(3);
	a = 5;
	b = 9;
	printf("%d\n", MAX(a,b));

	PINT_INT(MAX(a,b));

	return 0;
}
