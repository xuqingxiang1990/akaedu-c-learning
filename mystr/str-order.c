#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int len;
	char str[100], *dest, *d;
	char *s;
	scanf("%s",str);
	len = strlen(str);
	dest = malloc(len + 1);
	s = &str[len - 1];
	while(len!=0)
	{
		*d == *s;
		d++;
		s--;
		len--;
	}
	printf("%s\n", d);
	free(dest);

	return 0;
}
