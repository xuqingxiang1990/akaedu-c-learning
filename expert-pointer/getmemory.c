#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
void getmemory(char **p)
{
	char *q;
	q = (char *)malloc(100);
	*p = q;
}
#endif

void getmemory(char *p)
{
	p = (char *)malloc(100);
}

int main(void)
{
	char *str = NULL;
//	getmemory(&str);
	getmemory(str);
	printf("hello\n");
	strcpy(str, "heo");
	printf("%s\n", str);

	return 0;
}
