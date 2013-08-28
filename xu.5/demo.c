#include<stdio.h>

void print_table()
{
	int i, j;
	int a[20][20]={0};

	for(i = 0; i<11; i++)
		printf("%6d",i);
	putchar(10);
	for(i = 0; i<11; i++)
		printf("     _");
	printf("\n");
	for(i = 0; i<10; i++)
		for(j = 0; j<10; j++) {
			if(j==0)
				printf("%6d",i);
			else 
				printf("%6d",a[i][j+1]);
			if(j % 10==0)
				putchar(10);
			}
	putchar(10);
}

int main(void)
{
  print_table();
  putchar(10);
  return 0;
}
