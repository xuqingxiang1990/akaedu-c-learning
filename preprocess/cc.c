#include <stdio.h>

//#define DEBUG 0

//#define MAX 0
int main(void)
{

#ifdef DEBUG
	printf("debuf info ...\n");
#endif
#if DEBUG
	printf("2 debuf info ...\n");
#elif MAX
	#if MIN
		printf("3 debuf info ...\n");
	#endif

#endif
	printf("1234567\
8123456\n");
	return 0;
}
