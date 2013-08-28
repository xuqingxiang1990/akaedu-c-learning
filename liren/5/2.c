#include<stdio.h>
void print_str(char*s)
{
  char*p;
  p=s;
  while(*p!='\0')
  {
     if(*p=='/'&&*(p+1)=='*')
	 {
	   while(1)
	   {
	     if(*p=='*'&&*(p+1)=='/')
		   break;
		 p++;
	   }
	   p=p+2;
	 }
   putchar(*p);
   p++;
  }
}
int main()
{
  char*s="xuqing/xiang/*jsljo*/nihao";
  print_str(s);
  return 0;
}
