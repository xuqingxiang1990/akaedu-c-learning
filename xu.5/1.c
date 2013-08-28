#include<stdio.h>
int my(int *a,int *b)
{
	int x,y;
	scanf("%d%d",&x,&y);
	*a=x;
	*b=y;

}
int main()
{
	int a,b;
	my(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}

