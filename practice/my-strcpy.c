#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dst, char *src)
{
	int i, n, left;
	char *ret = dst;
	int *d = (int *)dst;
	int *s = (int *)src;

	 n = strlen(src) / 4;
//	for( i = 0; i <= n; i++)
	while(1)
	{
		*d = *s;
		d++;
		s++;
	}
	src = s;
	dst = d;

	left = strlen(src) % 4;
	while(left--)
	{
		*dst++ = *src++;
	}

}

int main(void)
{
	char *s1 = "xuqingxiang", *s2 = "ni hao";
	printf("%s\n", my_strcpy(s1, s2));
	putchar(10);

	return 0;
}

