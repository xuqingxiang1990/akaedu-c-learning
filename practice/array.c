#include <stdio.h>
#define N 100

int main(void)
{
	int i, a[N], j = 0, k = N / 2; 
	for(i = 1; i <= N; i++)
		if( i % 2 != 0)
			a[j++] = i;
		else
			a[k++] = i;

	for(i = 0 ; i < N; i++)
	{
		printf("%3d ", a[i]);
		if((i + 1) % 10 == 0)
			putchar(10);
	}
	putchar(10);


	return 0;
}
