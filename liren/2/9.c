#include<stdio.h>
#define N 10
int main()
{
  int a[N]={8,7,8,7,5,6,7,8,9,10};
  int *p=a,*q=a+N-1,temp;
  int i;
  while(p<q)
  {
    temp=*p;
	*p++=*q;
	*q--=temp;
  }
  for(i=0;i<N;i++)
    printf("%d ",a[i]);
 return 0;
}
