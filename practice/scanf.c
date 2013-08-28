#include <stdio.h>

int main(void)
{
	char str[100];
	scanf("%[^\n]", str);
	printf(str);

	return 0;
}
