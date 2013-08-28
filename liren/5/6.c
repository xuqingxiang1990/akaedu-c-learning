#include<stdio.h>
void inser(int a[],int n)
{
  int temp,i,j;
  for(i=2;i<=n;i++)
  {
    temp=a[i-1];
    for(j=i-2;j>=0;j--)
	  {
	    if(a[j]>temp)
		  a[j+1]=a[j];
		else
		 break;
	  }
	  a[j+1]=temp;
  }
}
int main()
{
  int a[100]={5,2,8,6,9,12,4};
  inser(a,7);
  int i;
  for(i=0;i<7;i++)
   printf("%d ",a[i]);
  printf("\n");
  return 0;
}
