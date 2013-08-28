#include<stdio.h>
void my_paixu(int a[],int n)
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
void my_xuzhe(int a[],int n)
{
		int i,j,max;
		int temp;
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
		// my_paixu(a,n);
		my_xuzhe(a,n);
		for(i=0;i<n;i++)
				printf("%d ",a[i]);
		putchar(10);
		return 0;
}
