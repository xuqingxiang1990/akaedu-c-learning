#include<stdio.h>
char *strcat(char *s1,char *s2)
{
  char *p;
  p=s1;
  while(*s2!='\0')
  {
    *p=*s2;
	p++;
	s2++;
  }
  *p='\0';
  return s1;
}
int main()
{
  char a[100],b[100];
  scanf("%s %s",a,b);
 puts(strcat(a,b));
  return 0;
}
