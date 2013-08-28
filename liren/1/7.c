#include<stdio.h>
int max_arr(int a[],int n)
{
  int max=a[0];
  int i;
  for(i=1;i<n;i++)
  {
    if(max<a[i])
	  max=a[i];
  }
  return max;
}
int main()
{
  int a[5]={2,34,12,52,5};
  printf("%d\n",max_arr(a,5));
  printf("%d\n",sizeof(int));
  printf("%d\n",sizeof(char));
  printf("%d\n",sizeof(long));
  printf("%d\n",sizeof(double));
  printf("%d\n",sizeof(float));
  return 0;
}
