#include<stdio.h>
void inser(int*a,int n)
{
 int i,j,temp;
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
  int i,n,a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  inser(a,n);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
