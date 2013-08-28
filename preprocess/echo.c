#include <stdio.h>

#define ECHO(s)  \
	do    \
	{    \
		gets(s);  \
		if(*s)   \
		put(s);    \
	}   \
	while(0)

int main(void)
{
	char str[100];
	int flag = 1;
	if(flag == 1)
		ECHO(str);
	else
		printf("NULL ding\n");
	
	return 0;
}
