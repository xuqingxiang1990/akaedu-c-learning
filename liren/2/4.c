#include<stdio.h>
int main()
{
  char *p,a[100];
  int count=0;
 scanf("%s",a);
 // for(p=&a[0];*p!='\0';p++)
   // if(*p==' ')
	 // count++;
  int i;
  for(i=0;a[i]!='\0';i++)
    if(a[i]==' ')
	  count++;
  printf("%d\n",count);
  return 0;
}
