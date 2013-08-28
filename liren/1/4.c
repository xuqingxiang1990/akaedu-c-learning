#include<stdio.h>
int main()
{
  int a[10]={2,4,6,7,3,22,1,3,13,11};
  int i,max;
  max=a[0];
  for(i=1;i<10;i++)
    if(a[i]>max)
	   max=a[i];
  printf("%d\n",max);
  return 0;

}
