#include <stdio.h>

int main(void)
{
	char buf[128];
	int i = 0;
	char ch;
	while(1)
	{
		char *p;
		p = fgets(buf, 128, stdin);
		if(p == NULL)
			break;

		while((ch = buf[i++])!='\0')
		{
			int count = 0;
			char a[32];

			if(!isalpha(ch))
				continue;
			do
			{
				a[count++] = ch;
				ch = buf[i++];

			}while(isalpha(ch));
			a[count] = '\0';
			printf("word = <%s>\n", a);
		}
	}
	
	return 0;
}
