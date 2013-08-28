#include<stdio.h>
int main()
{
  int a[10],*p,*q;
  int i;
  p=&a[9];
  q=&a[1];
  i=p-q;
  printf("%d\n",i);
  return 0;
}
