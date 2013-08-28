#include<stdio.h>
void print_str(char*s)
{
  int flag=1;
  char*p;
  p=s;
  for(;*p!=0;p++)
  {
    switch(flag)
	{
	 case 1:
	   if(*p!='/')
	     putchar(*p);
	   else
	     flag=2;
	   break;
	 case 2:
	   if(*p=='/')
		   putchar('/');
	   else if(*p=='*')
		  flag=3;
	   else
	    {
		 putchar('/');
		 putchar(*p);
		 flag=1;
		}
	   break;
	  case 3:
	   if(*p=='*')
	     flag=4;
	   else
	     flag=3;
	   break;
	  case 4:
	    if(*p=='/')
		  flag=1;
		else
		  flag=3;
	    break; 
	}
  }
}
int main()
{
  char*s="hel/lo//*n*/i/hao*//li/ren";
  print_str(s);
  putchar(10);
  return 0;
}
