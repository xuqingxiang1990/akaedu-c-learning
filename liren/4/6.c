#include<stdio.h>
void sort(int*a,int n)
{
  int i,j,temp;
  for(i=n;i>=2;i--)
    for(j=0;j<i-2;j++)
	{
	   if(a[j]>a[j+1])
	   {
	     temp=a[j];
		 a[j]=a[j+1];
		 a[j+1]=temp;
	   }
	}
}
void inser(int*a,int n)
{
  int i,temp,j;
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
void chose_sort(int*a,int n)
{
  int i,j,max,temp;
  for(i=n;i>=2;i--)
  {
    max=0;
	for(j=1;j<i;j++)
	{
	  if(a[max]<a[j])
	    max=j;
	}
       temp=a[max];
	   a[max]=a[i-1];
	   a[i-1]=temp;
  }
}
int main()
{
  int a[100],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%d",&a[i]);
  sort(a,n);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  inser(a,n);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  chose_sort(a,n);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
