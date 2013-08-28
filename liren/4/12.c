#include<stdio.h>
#include<string.h>
char *strcat(char*s1)
{
 char *p,*q;
 int len;
 len=strlen(s1);
  p=s1;
   while(*p!='/')
      p++;
 q=s1+len-1;
   while(*q!='/')
   {
	  *p=*q;
	    q--;
       p++;
	 }
   *p='\0';
   return p;
}

int main()
{
  char s1[100]="xuqing/*jf*/niaho",s2[100];
  //scanf("%s",s1);
  //scanf("%s",s2);
 printf("%s ",strcat(s1));
 printf("\n");
 return 0;
}
