#include<stdio.h>
#include<string.h>
/*char*my_strchr(char*s1,char n)
{
  char*p;
  for(p=s1;*p!='\0';p++)
  {
     if(*p=n)
	  return *p;
  }
}*/
int main()
{
  char a[100]="ajfjoj",ch='o';
  puts(strchr(a,3));
  return 0;
}
