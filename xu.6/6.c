#include<stdio.h>
#include<string.h>
int str_ch(char*s,char ch)
{
	char*p;
	for(p=s;*p!=0;p++)
		if(*p==ch)
			return 1;
		else
			return 0;
}

int str_position(char*s)
{
	int i;
	for(i=0;s[i]!=0;i++);
		if(s[i]==' ') {
			return i;
		}
		else
			return i;
}
int main(void)
{
	char s[100],ch,c;
	int len;
	fgets(s,sizeof(s),stdin);
	len=strlen(s);
	s[len-1]='\0';
	scanf("%c",&ch);
	if(str_ch(s,ch))
		printf("YES\n");
	else
		printf("NO\n");
	printf("%d\n",str_position(s));

	return 0;
}
