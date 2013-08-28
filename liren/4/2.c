#include<stdio.h>
#define N 100
int main()
{
  int n,m,i;
  int arrloop[N];
  int nptr;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
  arrloop[i]=i+1;
  nptr=0;
  for(i=0;i<n;i++)
  {
    int ncounted=0;
	while(ncounted<m)
	{
	  while(arrloop[nptr]==0)
	   nptr=(nptr+1)%n;
	   ncounted++;
	   nptr=(nptr+1)%n;
	}
	nptr--;
	if(nptr<0)
	nptr=n-1;
	if(i==n-1)
	 printf("%d\n",arrloop[nptr]);
	 arrloop[nptr]=0;
  }
  return 0;
}
