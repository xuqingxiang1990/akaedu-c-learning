#include <stdio.h>

int sum(int a, ...)
{
	int *p;
	int sum = 0;
	p = &a;
	while(*p != 0)
	{
		sum = sum + *p;
		p++;
	}

	return sum;
}

int max(int a, ...)
{
	int *p = &a;
	int max = 0;
	while(*p != 0)
	{
		if(*p > max)
			max = *p;
		p++;
	}

	return max;
}


int main(void)
{
	int ret;
	int s;
	s = sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0);
	printf("sum = %d\n", s);

	s = sum(9, 10, 0);
	printf("sum = %d\n", s);
	
	s = sum(9, 12,10, 0);
	printf("sum = %d\n", s);

	ret = max(1, 3, 4, 23, 12, 0);
	printf("ret = %d\n", ret);

	ret = max(5, 3, 901, 23, 23, 12, 0);
	printf("ret = %d\n", ret);

	ret = max(4, 2343, 434, 23, 12, 0);
	printf("ret = %d\n", ret);
	
	return 0;
}
