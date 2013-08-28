#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void convert(int num);
void oppose(int n);
int a[16];
void main(void)
{
  int num,jdz;
  char ans;
  while(1)
  {
	printf("请输入任意一个十进制整数: ");
	scanf("%d",&num);
	printf("\n");
	printf("其绝对值为: ");
	jdz=abs(num);
	printf("%d\n\n",jdz);
	printf("其原码为: \n");
	convert(jdz);
	printf("\n\n");
	if(num>=0)
	{
	  printf("其补码为: \n");
	  convert(jdz);
	  printf("\n\n");
	}
	else
	{
	  printf("其补码为: \n");
	  oppose(a[16]);
	  printf("\n\n");
	}
/*	printf("按回车键继续或按ESC键结束程序!!!\n");
	ans=getch();
	while(ans!=13 && ans!=27)
	{
	  ans=getch();
	}
	if(ans==13) system("cls");
	if(ans==27)
	{
	  system("cls");
	  printf("谢谢使用!!!\n");
	  break;
	}*/
  }
}

void convert(int num)       /*定义转化为原码的函数*/
{
  int i;
  a[0]=num%2;
  for(i=1;i<=15;i++)
  {
	a[i]=(num/2)%2;
	num/=2;
  }
  for(i=15;i>=0;i--)
	printf("%2d",a[i]);
}

void oppose(int n)        /*定义转化为补码的函数*/
{
  int i;
  for(i=0;i<=15;i++)
  {
	switch(a[i])
	{
	  case 1:a[i]=0;break;
	  case 0:a[i]=1;break;
	}
  }
  for(i=0;i<=15;i++)
  {
	a[i]++;
	if(a[i]>1) a[i]=0;
	else break;
  }
  for(i=15;i>=0;i--)
	printf("%2d",a[i]);
}
