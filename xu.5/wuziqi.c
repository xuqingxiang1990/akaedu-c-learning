#include<stdio.h>

int  foo(int a[][10])
{
	int i, j,k=0;
//	int a[20][20]={0};
	printf("          ");
	for(i = 0; i<11; i++)
		printf("%6d",i);
	putchar(10);
	
	printf("          ");
	for(i = 0; i<11; i++)
		printf("     _");
	printf("\n\n");

	for(i = 0; i<11; i++)
	{
		
		for(j = 0; j<13; j++) {
			if(j==0) {
					printf("%6d",k);
					k++;
				}
			else if(j==1)
				printf("   |");
			else 
				printf("%6d",a[i][j+1]);
			}

				putchar(10);
				putchar(10);
	}
	putchar(10);
}

int main(void)
{
	int chess[10][10];
	foo(chess);	

	return 0;
}
