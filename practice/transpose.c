#include <stdio.h>
#define N 5

void transpose(int a[][55555])
{
	int temp;
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%d ", a[i][j]);
		putchar(10);
	}
}


int main(void)
{
	int i, j, a[N][N];
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%2d ", a[i][j]);
		putchar(10);
	}
	
	putchar(10);
	int temp;
	for(i = 0; i < N; i++)
		for(j = i + 1; j < N; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%2d ", a[i][j]);
		putchar(10);
	}
	return 0;
}
