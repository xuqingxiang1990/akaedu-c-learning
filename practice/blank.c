#include <stdio.h>

int blank(char *str, char *store[])
{
	int i = 0;
	store[i++] = str;
	while(*str)
	{
		if(*str == ' ')
		{
			*str = '\0';
			store[i++] = str + 1;
		}
		str++;
	}
	return i;
}

int main(void)
{
	char str[] = "hello world i am a good body";
	char *store[100];
	int num, i;
	num = blank(str, store);
	printf("%d\n", num);
	for(i = 0; i < num; i++)
		printf("%s\n", store[i]);

	return 0;

}
