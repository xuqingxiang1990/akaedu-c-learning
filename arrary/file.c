#include <stdio.h>

int main(void)
{
	char str[128], *p;
	int count ;
	while(1)
	{
		int i = 0, j;
		char word[32];
		p = fgets(str, 128, stdin);
		if(p == NULL)
			break;
		while(str[i]!=0)
		{	
			count = 0;
			if(isalpha(str[i]))
				while(1)
				{
					word[count++] = str[i];
					i++;
					if(!isalpha(str[i]))
						break;
				}
				
			if(count!=0)
				printf("word = <%s>\n", word);
			i++;
		}
	}

	return 0;
}
