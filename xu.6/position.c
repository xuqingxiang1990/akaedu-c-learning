#include<stdio.h>
#include<string.h>

int position(char*s)
{
	int i,len,m=0,n=0;
	char*p;
	len=strlen(s);
	for(p=s;*p!=0;p++) {
		if(*p==' ')
			m++;
		n++;
		if(m==1)
			return n;
	}
	if(m==0)
		return len+1;
			
}

int main(void)
{
	char s[100];
	int len;
	fgets(s,sizeof(s),stdin);
	len=strlen(s);
	s[len-1]='\0';
	printf("%d\n",position(s));
	return 0;
}
