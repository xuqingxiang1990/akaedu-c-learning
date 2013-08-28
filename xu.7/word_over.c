#include<stdio.h>
#include<string.h>

char* word_over(char*s)
{
	int len ;
	char temp;
	int i,j,k=0;
	len = strlen(s);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
	while(k<len)
	{
		i=j=k;
		while(s[j]!=' ' && s[j]!='\0')
			j++;
		k=j+1;
		j--;
		for(;i<j;i++,j--)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
		}
	}
	return s;
}

int main(void)
{
	char s[100];
	int len;
	fgets(s,sizeof(s),stdin);
	len=strlen(s);
	s[len-1]='\0';
	printf("%s\n",word_over(s));

	return 0;
}
