#include<stdio.h>
#define N 10
{
  int a[N],*p,*q,i,temp;
  for(i=0;i<N;i++)
   scanf("%d",a[i]);
  p=a;q=a+N-1;
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
