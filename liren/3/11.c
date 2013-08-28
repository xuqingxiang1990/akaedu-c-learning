#include<stdio.h>
int search(int n,int max)
{
  int start=0,mid,end=max-1;
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
  int max,n,a[100],i;
  scanf("%d",&max);
  for(i=0;i<max;i++)
    scanf("%d",&a[i]);
  scanf("%d",&n);
  printf("%d\n",search(n,max));
  return 0;
}
