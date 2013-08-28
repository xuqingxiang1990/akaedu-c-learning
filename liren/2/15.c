#include<stdio.h>
#define LEN 8
int a[LEN]={1,2,3,5,6,7,42,56};
int binarysearch(int number)
{
  int mid start=0,end=LEN-1;
  while(start<=end)
  {
    mid=(start+end)/2;
	if(a[mid]<number)
	    start=mid+1;
    else if(a[mid]>number)
	    end=mid-1;
	else
	    return mid;
  }
  return -1;
}
int main()
{
  printf("%d\n",binarysearch(3));
  return 0;
}
