#include <stdio.h>
#include <string.h>
char *array(char *p)
{
	int len;
	int i = 0;
	char  a[100] = "xuqingxiang";
	len = strlen(a);
	while(a[i]!='\0')
	{
		*p = a[i];
		i++;
		p++;
	}
	p[len] = '\0';
	printf("%s\n", p);

	return p ;
}


int main(void)
{
	char *s;
	printf(" a = %s\n", array(s));
//	array(s);	
	return 0;
}
