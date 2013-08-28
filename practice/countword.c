#include <stdio.h>

int main(void)
{
	char ch;
	int counter = 0, i = 0;
	int flag;
	while((ch = getchar())!=EOF)
	{
		char word[32];
		if(isalpha(ch))
		{
			word[i++] = ch;
			flag = 1;
		}

		if(!isalpha(ch) && flag == 1)
		{
			word[i] = '\0';
			i = 0;
			flag = 0;
			counter++;
		}
		
	}
	printf("%d\n", counter);

	return 0;
}
