#include<stdio.h>
int main()
{
  char a[100]="xu qing xiang ni hao";
  char*p;
  int count=0,flag=1;
  p=a;
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
