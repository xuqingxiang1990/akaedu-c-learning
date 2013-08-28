#include<stdio.h>
#include<string.h>

char*repeat(char*s)
{
	int i,j;
	char str[] = " ",a[100];
	for(i = 0; s[i]!=0; i++)
		for(j = i+1; s[j]!=0; j++) {
			if(s[i]==s[j] && str[s[j]-'a']!=1)
				str[s[j]-'a']=1;
		}
	for(i = 0, j=0; i < 26; i++)
		if(str[i]==1) {
			a[j]=i+'a';
			j++;
		}
	for(i = 0; i < j; i++)
		s[i] = a[i];
	s[i] = '\0';
	return s;
}

int main(void)
{
	int len;
	char s[100];
	scanf("%s",s);
	printf("%s\n",repeat(s));

	return 0;
}
