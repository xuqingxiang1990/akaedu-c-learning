#include<stdio.h>

int count_bit_2(int num)             //消除最右边的1
{
	int counter = 0;
	if(num==0)
		return 0;
	while(num)
	{
		num = num & (num - 1);
		counter++;
	}

	return counter;
}

int count_bit_1(int num)
{
	int counter = 0, i;
	for (i = 0; i < 32 ; i++) {                  //遍历整个32位
		if ((num & ( (unsigned)1<<i)))
			counter++;
	}

	return counter;
}

int count_num(int num, int num1)
{
	 
}
int main (void)
{
	int ret = 0,i,num;
	scanf("%d",&num);
	for(i = 1; i <= 100; i++)
		ret += count_bit_1(i);
	printf(" %d ", ret);
	putchar(10);
	printf(" %d ", count_bit_2(num));
	putchar(10);

	return 0;

}
