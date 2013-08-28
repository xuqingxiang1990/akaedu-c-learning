#include<stdio.h>
struct student{
				int score;
				char name[100];
};
void print_s(struct student*s,int n)
{
				int i;
				for(i=0;i<n;i++)
								printf("%d %s ",s[i].score,s[i].name);
}
void print_max(struct student*s,int n)//最大值
{
				int i,max,j,k;
				max=s[0].score;
				j=0;
				for(i=1;i<n;i++)
				{
								if(max<s[i].score)
								{
												max=s[i].score;
												j=i;
								}

				}
				printf("%d\n",j);
				printf("%d %s ",s[j].score,s[j].name);

}
void print_maopao(struct student*s,int n)//冒泡排序
{
				int i,j;
				struct student temp;
				for(i=1;i<n;i++)
								for(j=0;j<n-i;j++)
								{
												if(s[j].score>s[j+1].score)
												{
																temp=s[j];
																s[j]=s[j+1];
																s[j+1]=temp;
												}
								}
					for(i=0;i<n;i++)
								printf("%d %s ",s[i].score,s[i].name);


}
void print_xuanzhe(struct student*s,int n)//选择排序
{
				int i,j,max;
	    	struct student temp;
				for(i=n;i>=2;i--)
				{
								max=0;
								for(j=1;j<i;j++)
								{
												if(s[max].score>s[j].score)
																max=j;
																temp=s[max];
																s[max]=s[j-1];
																s[j-1]=temp;
								}
				}
					for(i=0;i<n;i++)
								printf("%d %s ",s[i].score,s[i].name);


}
void print_inser(struct student*s,int n)//插入排序
{
				int i,k;
				struct student temp;
				for(i=2;i<=n;i++)
				{
								temp=s[i-1];
								for(k=i-2;k>=0;k--)
								{
												if(temp.score<s[k].score)
																s[k+1]=s[k];
												else
																break;

								}
								s[k+1]=temp;
				}
					for(i=0;i<n;i++)
								printf("%d %s ",s[i].score,s[i].name);


}
int main()
{
				struct student s[5];
				int i;
    		for(i=0;i<5;i++)
								scanf("%d %s",&(s[i].score),s[i].name);
				print_s(s,5);
				printf("\n");
				print_max(s,5);
				printf("\n");
				print_maopao(s,5);
				printf("\n");
				print_xuanzhe(s,5);
				printf("\n");
			  print_inser(s,5);
				printf("\n");
				return 0;
}
