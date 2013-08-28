#include<stdio.h>
#include<string.h>
char*print_str(char*s)
{
  char *p,*q;
  p=s;
  while(*p!='\0')
   p++;
  /*int len;
  len=strlen(s);
  q=s+len-1;
  while(*q!='/')
  {
    *p=*q;
	q--;
	p++;
  }*/
  *p='\0';
  return p;
}
int main()
{
  char a[100]="xuqingxian/*你好*/nihao";
  printf("%s ",print_str(a));
  return 0;
}
