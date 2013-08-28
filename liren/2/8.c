#include<stdio.h>
int main()
{  int i,a[10],*p;
   for(p=a;p<a+10;p++)
    scanf("%d",p);
  for(p=a+9;p>a;p--)
    printf("%d ",*p);
  return 0;
}
