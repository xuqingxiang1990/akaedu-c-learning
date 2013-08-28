#include <stdio.h>

char *my_strtok(char *str, const char *delim)
{
	static char *p;
	const char *q = delim;
	char *temp;
	int i = 0;
	if(str != NULL)
		p = str;
	if(p == NULL || q == NULL)
		return NULL;
	while(*p)
	{
		q = delim;
		while(*q)
		{
			if(*p == *q)        //"xu;;;;;;''''qing;;;'''xinag;;;;''hello";
			{
				*p = '\0';
				while(1)
				{
					p++;
					int j = 0;
					q = delim;
					while(*q)
					{
						if(*p == *q)	
						{
							i++;
							j++;
						}
						q++;
					}
					if(j == 0)
					{
					p--;
						break;
					}
				}
				return p++ -i;
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

int main(void)
{
	char str[] = "xu;;;;;;''''qing;;;'''xinag;;;;''hello";
	printf("%s\n", my_strtok(str, ";'"));
	char *p;
	while(p = my_strtok(NULL, ";'"))
		printf("%s\n", p);

	return 0;
}
