#include<stdio.h>
#include<stdio.h>
int main(void)
{
	int m, n,a[100],i=0,j,w,flag=1;
	printf("请输入一个整数\n");
	scanf("%d", &m);
	w=m;
	m=abs(m);
	while(m!=0)
	{
		n=m%2;
		a[i]=n;
		m=m/2;
		i++;
	}

	if(w==0)
	{
		
		printf("%d的原码是:\n\n",w);
		printf(" %d\n",w);
		printf("%d的反码是:\n\n",w);
		printf(" %d\n",w);
		printf("%d的补码是:\n\n",w);
		printf(" %d\n",w);
	}
	if(w>0)                                 //正数
	{
		printf("%d的原码是:\n\n",w);
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);
		putchar(10);

		printf("%d的反码是:\n\n",w);
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);
		putchar(10);

		printf("%d的补码是:\n\n",w);
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);
		putchar(10);
	}

	else if(w<0)                         //负数
	{	
		printf("%d的原码是:\n\n",w);
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);

		for(j=i-1;j>=0;j--) {
			if(a[j]==1)
				a[j]=a[j]-1;
			else 
				a[j]=a[j]+1;
		}

		putchar(10);
		printf("%d的反码是：\n\n",w);
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);
		putchar(10);	

		printf("%d的补码是：\n\n",w);
		for(j=0;j<i;j++)
		{
			a[j]++;
			if(a[j]>1)
				a[j]=0;
			else
				break;
		}
		for(j=i-1;j>=0;j--)
			printf(" %d ",a[j]);
		putchar(10);	
	}
	putchar(10);
	return 0;
}
