#include<stdio.h>
int main()
{
 int i,m,n,count,ntr,myloop[1000];
 scanf("%d%d",&n,&m);
 for(i=0;i<n;i++)
  myloop[i]=i+1;
 ntr=0;
 for(i=0;i<n;i++)
 {
   count=0;
   while(count<m)
   {
     while(myloop[ntr]==0)
	  ntr=(ntr+1)%n;
	 count++;
	 ntr=(ntr+1)%n;
   }
   ntr--;
   if(ntr<0)
    ntr=n-1;
   if(i==n-1)
    printf("%d",myloop[ntr]);
   myloop[ntr]=0;
 }
 printf("\n");
 return 0;
}
