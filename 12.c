#include<stdio.h>
int main()
{
	int i,j;
	char s[100]="xu qing xiang ni hao",s1[100];
	for(i=4,j=0;i<12;i++)
	{
		s1[j]=s[i];
		j++;
		}
	printf("%s",s1);
	return 0;
}
