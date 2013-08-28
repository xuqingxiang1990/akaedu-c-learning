#include<stdio.h>
#include"head.h"

int main(void)
{
	int a,b;
	scanf("%d%d\n",&a,&b);
	printf("add:%d\n",add(a,b));
	printf("sub:%d\n",sub(a,b));
	printf("mul:%d\n",mul(a,b));
	printf("div:%d\n",div(a,b));

	return 0;
}
