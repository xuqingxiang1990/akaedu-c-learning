#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("abc.txt","w");
	fp2=fopen("a.txt","r");
	while(fp1==NULL||fp2==NULL) {
		printf("ERROR");
		exit(0);
	}
	while(ch=fgetc(fp2)!=EOF)
		fputc(ch,fp1);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
