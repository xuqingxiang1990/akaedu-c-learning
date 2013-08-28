#include<stdio.h>
int main()
{
  int i=5;
  printf("%d\n",((i++)+(++i)+(++i)+(i++)+(++i)));
  return 0;
}
