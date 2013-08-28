#include <stdio.h>
#include <string.h>

char hex[4] = "hello";
int main(void)
{
	printf("%s\n", hex);
	printf("%d %d\n", strlen(hex), sizeof(hex));

	return 0;
}
