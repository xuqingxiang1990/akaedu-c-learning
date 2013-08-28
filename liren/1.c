#include<stdio.h>
void print_my(char*s)
{
  char*q;
  s=0;
  q=s;
  for(q=s;*q!='\0';q++);
  {
    if(*q=='/')
	 s==1;
	else if(s==1)
	 {
	   if(*q=='*')
	    s=2;
	   else if(s==2)
	   {
	     while(1)
		 {
		   if(s==2)
		     break;
		 }
		 s=3;
	   }
	 }
  }
  if(s==0)
  putchar(*s);
}
int main()
{
  char a[100]="hello/*jfo*/nihao";
  print_my(a);
  printf("\n");
  return 0;
}
