#include<stdio.h>
#define LEN 8
int a[LEN]={5,2,4,7,1,45,23,12};
void merge(int start ,int mid ,int end)
{
  int n1=mid-start+1;
  int n2=end-mid;
  int left[n1],right[n2];
  int i,j,k;
  for(i=0;i<n1;i++)
    left[i]=a[start+i];
  for(j=0;j<n2;j++)
    right[j]=a[mid+1+j];
  i=j=0;
  k=start;
   while(i<n1&&j<n2)
	   if(left[i]<right[j])
	      a[k++]=left[i++];
	   else
	      a[k++]=right[j++];
    while(i<n1)
	   a[k++]=left[i++];
	while(j<n2)
	   a[k++]=right[j++];

}
void sort(int start,int end)
{
   int mid,i;
   if(start<end)
   {
      mid=(start+mid)/2;
	  sort(start,mid);
	  sort(mid+1,end);
	  merge(start,mid,end);
	  for(i=0;i<LEN;i++)
	   printf("%d ",a[i]);

   }
}
int main()
{
 sort(0,LEN-1);
 printf("\n");
 return 0;

}
