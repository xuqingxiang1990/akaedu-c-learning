#include <stdio.h>

void repeat(int num)
{
	int a[100], x, y; 
	int i = 0, j, counter = 0;
	int flag[100];
	while(x)
	{
		a[i] = num % 10;
		x = num / 10;
		num = x;
		i++;
		y = i;
	}
	for(i = 0; i < 10; i++)
		flag[i] = 0;
	for(i = 0; i < y; i++)
			for(j = i + 1; j < y; j++)     
				if(a[i] == a[j] && flag[a[i]] == 0)
				{
				  flag[a[i]] = 1;
				  counter++;
				}
	if(counter == 0)
		printf("No repeat digit");
	else
	{
		for(i = 0; i < 10; i++)
		  if(flag[i] == 1)
			printf("%d ", i);
	}
}

void repeat1(num)
{
	int digit[10] = {0};
	int r;
	while(num)
	{
		if(digit[num % 10] == 1)
			break;
		else
			digit[num % 10] = 1;
		num = num / 10;
	}
	if(num)
		printf("YES");
	else
		printf("NO");
}

int main(void)
{
	int num;
	scanf("%d", &num);
	repeat(num);
	repeat1(num);
	putchar(10);

	return 0;
}
