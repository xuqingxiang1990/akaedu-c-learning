#include<stdio.h>
int* max(int* a,int* b)
{
  if(*a>*b)
   return a;
  else
   return b;
}

int main()
{
  int *p,x,y;
  x=9;y=2;
  p=max(&x,&y);
  printf("%d\n",*p);
}
