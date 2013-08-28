#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strtok(char *str, const char *delim)
{
	static char *p = NULL;
	const char *q = delim;
	char *temp;
	int i;
	if(str != NULL)
		p = str;
	if(p == NULL || q == NULL)
		return NULL;
	i = 0;
	while(*p)
	{
		q = delim;
		while(*q)
		{

			if(*q == *p)
			{
				*p = '\0';
				return p++ - i ;
			}
			q++;
		}
		p++;
		i++;
	}

	if(*p == '\0')
	{
		temp = p;
		p = NULL;
		return temp - i;
	}
}

int main(int argc, char *argv[])
{
	char str[100] = "hello;word;,owfj";
	char *p;
	printf("%s\n", my_strtok(str, ";,"));
	while(p = my_strtok(NULL, ";,"));
		printf("%s\n", p);

	return 0;
}
