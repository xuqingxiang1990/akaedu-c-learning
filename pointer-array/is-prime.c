#include <stdio.h>
#include <math.h>

int *print_prime(int m, int n)
{
  int i, j, flag =1, k , a[1000];
  for(i = m; i <= n; i++)
  {
	if(i == 1)
		flag = 0;
	else if(i == 2)
		flag = 1;
	for(j = 2; j <= (int)sqrt(i) ; j++)
		if( i % j == 0)
		{
			flag = 0; 
			break;
		}
		else 	
			flag = 1;
	if(flag)
	{
		printf("%5d ",i);
		k++;
		if(k % 10 == 0)
			putchar(10);
	}
  }
  putchar(10);
}

int main(void)
{
  int n, i, m;
  scanf("%d%d", &m, &n);
  printf(" %d 与 %d 之间的素数为:\n", m, n);
  print_prime(m, n);

  return 0;
}
