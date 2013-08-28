#include <stdio.h>
#include <stdlib.h>

//int n = 100;
#define N 100

int a[N];

int main(void)
{


	char *p = NULL;
	int size;

	p = p + 0x2000;
	printf("p = %p\n", p);
	p = malloc(13);
	printf("p = %p\n", p);

	free(p);
	p = malloc(4);
	printf("p = %p\n", p);

	free(p);
	p = malloc(4);
	printf("p = %p\n", p);

	while(1);


}
