#include<stdio.h>
#include<string.h>
char* print_str(char*s)
{
  char*p,*q,*m;
  int len,count=0;
  len=strlen(s);
  int flag=1;
  p=s;
  while(*p!='/')
   p++;
   q=s+len-1;
  while(*q!='/')
  {
    *p=*q;
	p++;
	q--;
  }

 return s;
}
int main()
{
  char a[100]="xuq/ing/*xiangsjf*/nihao";
 puts(print_str(a));
  return 0;
}
