#include<stdio.h>
int main()
{
  int flag=1,count=0;
  char*p="  xin  sino   aif o  afoej j";
while(*p!='\0')
  {
    if(*p==' ')
	 flag=0;
	else if(flag==0)
	{
	  flag=1;
	  count++;
	}
  }
  printf("%d",count);
  return 0;
}
