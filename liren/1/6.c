#include<stdio.h>
void swap(int*x,int*y)
{
 int temp=*x;
     *x=*y;
	 *y=temp;
}
int main()
{
  int a=5,b=6;
  swap(&a,&b);
  printf("%d %d\n",a,b);
  return 0;
}
