#include<stdio.h>
#define N 7
int a[N]={1,2,3,4,5,6,7};
int chazhao(int n)
{
  int start=0,mid,end=N-1;
  while(start<=end)
  {
    mid=(start+end)/2;
	if(mid>n)
	  end=mid-1;
	else if(mid<n)
	  start=mid+1;
	else
	  return mid;
  }
}
int main()
{
 printf("%d\n",chazhao(5));
 return 0;
}
