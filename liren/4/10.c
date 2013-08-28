#include<stdio.h>
void print_str2(char*s)
{
  char*p;
  int flag=1;
  for(p=s;*p!=0;p++)
  {
    if(*p==' ')
	 flag=0;
	else if(flag==0)
	{
	   flag=1;
	   putchar(' ');
	   putchar(*p);
	}
	else
	 putchar(*p);
   }
}
int main()
{
 char a[100]="    xu   qing   xiang   ni    hao  li    ren";
 print_str2(a);
 printf("\n");
 return 0;
}
