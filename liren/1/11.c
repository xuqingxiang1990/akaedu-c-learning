#include<stdio.h>
#define N 10
int main()
{
  int i,*p,sum=0,a[10];
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  for(p=a;p<a+N;p++)
    sum=sum+*p;
  printf("%d\n",sum);
  return 0;
}
