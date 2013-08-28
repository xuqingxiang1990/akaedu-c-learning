#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("abc.txt","w"))==NULL) {
		printf("Error");
		exit(0);
	}
	while((ch=getchar())!='#')
		fputc(ch,fp);
	fclose(fp);
	return 0;
}
