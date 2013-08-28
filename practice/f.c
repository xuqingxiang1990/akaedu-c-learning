#include <stdio.h>

void say_hello(const char *str)
{
	printf("Hello %s\n", str);
}
 
int main(void)
{
	char s[100];
	scanf("%s", s);
	void(*f)(const char *) = say_hello;
	f(s);
	return 0;
}
