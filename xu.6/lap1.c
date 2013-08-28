#include<stdio.h>

int main(void)
{
	char str[]=" ";
	char s[100];
	int i, j;
	scanf("%s",s);
	for(i = 0; s[i]!=0; i++)
		for(j = i+1; s[j]!=0; j++) {
			if(s[i]==s[j] && str[s[j]-'a']!=1)
				str[s[j]-'a']=1;
		}
	for(i = 0; i < 26; i++)
		if(str[i]==1)
			printf("%c ",i+'a');
	putchar(10);
	return 0;
}
