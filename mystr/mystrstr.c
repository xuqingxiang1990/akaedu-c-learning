#include <stdio.h>

char *mystrstr(char *str1, char *str2)
{
	char *p, *m;
	char *n;
	p = str1;
	if(*m == 0)
		return p;
	while(*p)
	{
		n = p;
		m = str2;
		while(*n && *m && *m == *n)
		{
			n++;
			m++;
		}
		if(*m == 0)
			return p;
		p++;
	}
}

int main(void)
{
	char str1[] = "hello world hello akaedu", str2[] = "ld";
	printf("%s\n", mystrstr(str1, str2));

	return 0;
}
