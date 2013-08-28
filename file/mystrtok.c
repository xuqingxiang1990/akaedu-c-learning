#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrtok(char *str, const char *delim) 
{
	static char *p = NULL;
	const char *q = delim;
	char *res;
	int i;
	if (str != NULL) 
		p = str;
	if (p == NULL || q == NULL)
		return NULL;
	i = 0;
	while (*p)
	{
		q = delim;
		while (*q)
		{
			if (*q == *p)
			{
				*p = '\0';
				while(1)
				{
					int j = 0;	
					p++;
					q = delim;
					while(*q)
					{
						if(*q == *p)
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
				return p++ - i;
			}
			q++;
		}
		p++; i++;
	}
	if (*p == '\0') {
		res = p;
		p = NULL;
		return res - i;
	}
}

int main(int argc, char *argv[])
{
	char str[100] = "hello;;;;;,,,,; asdf;,,,;;:::;; e3 ;;:::,,;;df ;; aewr ;qdsf;d";
	char *p;
	printf("%s\n", str);
	printf("%s\n",mystrtok(str, ";:,"));
	while (p = mystrtok(NULL,";:,"))
		printf("%s\n",p);

	return 0;
}
