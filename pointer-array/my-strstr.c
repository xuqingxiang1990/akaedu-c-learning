#include <stdio.h>
#include <string.h>

char *my_scanf(char *str1, int size)
{
	int len;
	fgets(str1, size, stdin);
	len = strlen(str1);
	str1[len - 1] = '\0';
	
	return str1;
}

char *my_strstr(char *str1, char *str2)
{
	char *p, *m, *n;
	p = str1;

	while(*p!=0)
	{
		m = p;
		n = str2;
		while(*m!=0 && *n!=0 && *m == *n)
		{
			m++;
			n++;
		}
		if(*n == '\0')
			return p;
		p++;
	}
}

int main(void)
{
	#if 0
	char str1[100], str2[100];
	my_scanf(str1, sizeof(str1));
	my_scanf(str2, sizeof(str2));
	printf("%s\n", my_strstr(str1, str2));
	#endif 

	char str1[] = "xuqingxiang", str2[] = "qing";
	printf("%s\n", my_strstr(str1, str2));

	return 0;
}
