#include <stdio.h>

int main(int argc, char *argv[])
{
	char str[100];
	scanf("%[^\n]", str);
	printf("output:\n%s\n", str);

	return 0;
}
