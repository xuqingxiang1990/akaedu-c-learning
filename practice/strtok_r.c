#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "xu men 23;qing men 24;xiang men 19";
	char *p[10];
	char *outerptr, *interptr;
	char *buf;
	int i = 0, j = 0;
	buf = str;
	while((p[i] = strtok_r(buf, ";", &outerptr)) != NULL)
	{
		buf = p[i];
		while((p[i] = strtok_r(buf, " ", &interptr)) != NULL)
		{
			buf = NULL;
			i++;
		}
		buf = NULL;
	}
	for(j = 0; j < i; j++)
		printf("<%s>\n", p[j]);
	
	return 0;
}
