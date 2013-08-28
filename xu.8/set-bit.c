#include <stdio.h>

int set_bit(int num, int pos, int value)            //把第pos位至value位（0|1）
{
	if(value == 1)
		num |= ((unsigned)1 << pos);
	else if(value == 0)
		num &= ~((unsigned)1 << pos);
	
	return num;
}

int get_bit(int num, int pos)                        //判断pos位是1或者是0
{
	if(num & ((unsigned)1 << pos))
		return 1;
	else
		return 0;
}

int set_bit_filed(int num, int pos, int value, int len)
{
	int a[] = {1, 3, 7, 15, 31, 63, 127, 255};
	num = num & ~(a[len-1] << pos);
	num = num | (value << pos);

	return num;
}
int main(void)
{
	int num, pos, value,len;
	scanf("%d %d %d%d", &num, &pos, &value, &len);
	printf("第%d位至1后为:\n0x%x\n",pos,  set_bit (num, pos, 1));
	printf("清零后为:\n0x%x\n", set_bit (num, pos, 0));
	printf("%d的第%d位是\n%x\n", num, pos, get_bit(num, pos));
	printf("%d的第%d位被%d替换后为\n0x%x\n",num, pos, value, set_bit_filed(num, pos, value, len));
	return 0;
}

