#include<stdio.h>

double ave(double a, double b)
{
	double c;
	c=(a+b)/2;
	return c;
}

int main(void)
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	printf("%lf\n",ave);
	return 0;
}
