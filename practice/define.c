#include <stdio.h>
#define DEBUG 0
#define TWO

#define MAX(a,b,c) a##b##c
#define STR(a,b,c)a##b##c
int main(void)
{
//	printf("%s\n", STR("aa", "bb", "cc"));
	#if DEBUG
	printf("debugging\n");
	#endif
	printf("running\n");
	
	#ifdef ONE
		printf("1\n");
	#elif TWO
		printf("2");
	#else
		printf("3");
	#endif
	return 0;
}
