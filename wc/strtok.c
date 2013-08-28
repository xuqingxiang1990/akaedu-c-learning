#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[] = "abc<html><head><title>404 Not Found</title></head>";
	char *p;
	printf("buf = %s\n", buf);
	p = buf;
	printf(" p = %p\n", p);
	p = strtok(p, "<");
	printf(" p = %s\n", p);
	while(1)
	{
		char *p1, *p2;
		p1 = strtok(NULL, "<>");
		printf("p1 = %s\n", p1);
		if(p1 == NULL)
			break;
	}
	return 0;
}
