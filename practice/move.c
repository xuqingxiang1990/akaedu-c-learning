#include <stdio.h>
#include <string.h>

void rightshift(char *arr, int n, int k)
{
	while(k--)
	{
		char t = arr[n - 1];
		int i;
		for(i = n - 1; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = t;
	}
}

int main(void)
{
	int n, k, len, i;
	char a[100];
	scanf("%s",a);
	len = strlen(a);
	rightshift(a, len, 2);
	printf("%s ", a);
	putchar(10);	
	
	return 0;
}
