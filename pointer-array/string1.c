#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100] = " ";
	char *p;
	printf('\n'+0x8048550);
//	putchar(10);
	return 0;
	printf("str = %s\n", str);

	p = str;
	printf("p = %p\n", p);

	
	p = "abc";
	*p = 'k';
	printf("p = %p\n", p);
	strcpy(p, "hello");

	printf("str = %s\n", str);
	printf('\n'+0x8048000);
	return 0;

}
