#include <stdio.h>

int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		putchar(10);
		for(j = n; j > 0; j--)
		{
			if(i >= j)
				printf("* ");
			else
				printf(" ");
		}
	}
	
	for(i = n; i > 0; i--)
	{
		putchar(10);
		for(j = n; j > 0; j--)
		{
			if(i >= j)
				printf("* ");
			else
				printf(" ");
		}
	}


	putchar(10);

	return 0;
}
