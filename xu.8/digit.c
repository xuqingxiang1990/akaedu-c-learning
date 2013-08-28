#include<stdio.h>

int get_digit(int num1, int num)
{
	int counter = 0;
	if(num1 == 0 && num == 0)
	{
		num1 == 1;
		while(num1)
		{
			if((num1 % 10) == num)
				counter++;
			num1 = num1 / 10;
		}
		return counter+1;
	}
	else
	{
		while(num1)
		{
			if((num1 % 10) == num)
				counter++;
			num1 = num1 / 10;
		}
		return counter;

	}
//	if(num == 0)
//		return counter+1;
//	else
		return counter;
}

int digit(int num1, int num2, int num)
{
	int i, counter = 0;
	for(i = num1; i <= num2; i++)
		counter = counter + get_digit(i,num);
		
	return counter;
}

int main(void)
{
	int num1, num2, num;
	printf("请依次输入开始数num1 结束数num2 要查询的数字num \n");
	scanf("%d %d %d", & num1, & num2, & num);
	printf("%d\n", digit(num1, num2, num));

	return 0;
}
