#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[100], b[100];
	int len;
	char str[100];
	fgets(a, sizeof(a), stdin);
	len=strlen(a);
	a[len-1]='\0';
	fgets(b, sizeof(b), stdin);
	len=strlen(b);
	b[len-1]='\0';
	printf("%s\n",strcat(a,b));
	return 0;
}
