#include <stdio.h>
#include <string.h>

int palindrome(char s[])
{
	int i, j, len, flag = 1;	
	len = strlen(s);
	for(i = 0, j = len - 1; i < j; i++, j--)
		if(s[i] != s[j])
			return 0;
	return 1;
}

int main(void)
{
	char s[100];
	scanf("%[^\n]", s);
	palindrome(s);
	if(palindrome(s))
		printf("YES num is palindrome!\n");
	else
		printf(" Sorry num is not !!!!\n");
	
	return 0;
}
