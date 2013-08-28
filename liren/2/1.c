#include<stdio.h>
int main()
{
  char a[100],*p;
  int i,count=0;
  scanf("%s",a);
  for(i=0;a[i]!='\0';i++)
     count++;
  for(p=&a[count];p>=a;p--)
    printf("%c ",*p);
   printf("\n";
   return 0;
}
