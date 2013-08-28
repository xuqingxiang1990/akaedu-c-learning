#include <stdio.h>

int main(void)
{
	int count = 0, num;
	int i, j, k;
	for(i = 1; i < 5; i++)
		for(j = 1; j < 5; j++)
			for(k = 1; k < 5; k++)
				{
					if(i != j && j != k && i != k)
						{
							count++;
							printf("%d %d %d \n", i, j, k);
						}
				}
	printf("counter = %d\n", count);

	return 0;
}
