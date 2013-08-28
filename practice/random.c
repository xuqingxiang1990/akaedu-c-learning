#include <stdio.h>
#include <time.h>

int main(void)
{
	int a[16], i, j;
	srand(time(NULL));
	for(i = 0; i < 16; i++)
	{
		a[i] = rand() % 19;
		for(j = i - 1; j >= 0; j--)
		{
			if(a[i] == a[j])
			{
				i = i -1;
			 	break;
			}
			else
				continue;
		}
	}
	for(i = 0; i < 16; i++)
	{
		printf("%-2d ", a[i]);
		if((i + 1) % 8 == 0)
			putchar(10);
	}

	return 0;
}
