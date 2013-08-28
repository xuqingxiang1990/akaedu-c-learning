#include <stdio.h>
int greatest(int a, int b)
{
	int i;
	for(i = a < b ? a : b; i > 0; i--)
		if(a % i == 0 && b % i == 0)
				return i;
}

int greatest2(int a, int b)
{
	int temp;
	int r, r1;
	int m, n;
	m = a, n = b;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	do
	{	
		r = a % b;
		a = b;
		b = r;
	}while(r != 0);
	r1 = (m / a) * n;
	printf("最小公倍数为：\n%d \n", r1);
	return a;

}
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
//	printf("最大公约数为:\n%d\n", greatest(a, b));
	printf("最大公约数为:\n%d\n", greatest2(a, b));
	

	return 0;
}
