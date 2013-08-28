#include<stdio.h>
#include<string.h>
int str_x(char*s,char ch,int n)
{
	char*p;
	int count=0;
	for(p=s;*p!=0;p++) {
		if(*p==ch)
			count++;
	}
	if(count==n)
		return 1;
	else
		return 0;
}

int main()
{
	char s[100],ch;
	int n,len;
	fgets(s,sizeof(s),stdin);
	len=strlen(s);
	s[len-1]='\0';
	scanf("%c%d",&ch,&n);
	if(str_x(s,ch,n))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
