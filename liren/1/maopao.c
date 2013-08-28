#include<stdio.h>
#define N 10
void paixu(int*a,int n)
{
   int i,j;
   int temp;
   for(i=1;i<n;i++)
     for(j=0;j<n;j++)
	  {
	    if(a[i]<a[j])
		  {
		    temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		  }
	  }
}

int main()
{
  int i,a[100];
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  paixu(a,N);
  for(i=0;i<N;i++)
    printf("%d ",a[i]);
 printf("\n");
  return 0;
}
