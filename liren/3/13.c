#include<stdio.h>
char*my_strstr(char*s1,char*s2)
{
  char *p,*q,*l;
  p=s1;
  for(;*p!='\0';p++)
  {
   l=p;
   for(q=s2;(*p==*q)&&(*p!='\0')&&(*q!='\0');q++,p++);
    if(*q=='\0')
    return l;
  }
  return NULL;
}
int main()
{
 char a[100]="abcdefghijk",b[10]="gh";
 puts(my_strstr(a,b));
  return 0;
}
