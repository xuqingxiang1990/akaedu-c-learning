#include <stdio.h>
#define DEBUG(x) printf("<%s>@(%s) line: %d " #x " = %d\n", __func__, __FILE__, __LINE__, x)
void print(void)
{
	int i = 100;
	DEBUG(i);
}
int main(void)
{

	int i;
	DEBUG(i);

	printf(" line = %d\n", __LINE__);
	printf(" file = %s\n", __FILE__);
	printf(" date = %s\n", __DATE__);
	printf(" time = %s\n", __TIME__);
//	printf(" stdc = %s\n", __STDC__);
	printf(" func = %s\n", __func__);

	return 0;
}
