#include <stdio.h>
#define BUFER_SIZE 128
#ifndef BUFER_SIZE
#define BUFER_SIZE 256
#endif

#if 0

int a;
int b;
int c;
int d;

#endif
//#define MAX 2

void myfunc(void)
{
	printf("%s\n", __func__);
}

int main(void)
{	
	#if DEBUG
		printf("1 is ok\n");
		#if MAX
			printf("2 is ok\n");
		#endif
	#else
		printf("3 is ok\n");
	#endif
	myfunc();
	printf("%s\n", __func__);
	#ifdef BUFER_SIZE
	printf("%d\n", BUFER_SIZE);
	#endif
	
	return 0;
}
