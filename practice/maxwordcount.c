#include <stdio.h>
#include <string.h>

void wordcount(char *str)
{
	int flag[26], i, j, counter[26];
	for(i = 0; i < 26; i++)
	{
		flag[i] = 0;                      //abcdefgabc
		counter[i] = 1;
	}
	for(i = 0; str[i]!='\0'; i++)
		for(j = i + 1; str[j]!='\0'; j++)
			if(str[i] == str[j] && flag[str[i] - 'a'] == 0)
			{
				counter[str[i] - 'a']++;
				flag[str[i] - 'a'] = 1;
			}
	for(i = 0; i < 26; i++)
		if(flag[i] == 1)
			printf("%c %d ", i + 'a', counter[i]);
	putchar(10);
				
}
	

int main(void)
{
	int len;
	char str[100];
	fgets(str, sizeof(str), stdin);
	len = strlen(str);
	str[len - 1] = '\0';
	wordcount(str);

	return 0;
}
