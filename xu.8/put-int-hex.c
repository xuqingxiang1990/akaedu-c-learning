#include<stdio.h>


/*void put_char_hex(char byte)
{
	put_hex((byte >> 4) & 0x0f);
	put_hex((byte >> 0) & 0x0f);

	return ;
}

void put_int_hex(int num)
{
	putchar('0');
	putchar('x');
	put_char_hex((num >> 24) & 0xff);
	put_char_hex((num >> 16) & 0xff);
	put_char_hex((num >> 8) & 0xff);
	put_char_hex((num >> 0) & 0xff);

	return ;
}*/

void put_hex(int hex)                             //十六进制
{
	char hex1[16]="0123456789abcdef";
	putchar(hex1[hex]);
	
	return ;
}

void put_int_hex(int num)                  
{
	int i;
	putchar('0');
	putchar('x');
	for(i = 7; i>=0; i--)
		put_hex((num >> (4*i)) & 0x0f);

	return ;
}

void put_char_oct(int byte)                  //八进制
{
	int i;
	char s[9] = "01234567";
	putchar(s[byte]);

	return ;
}

void put_int_oct(int num)
{
	int i;
	putchar('0');
	for(i = 10; i>=0; i--)
		put_char_oct((num >> (3*i)) & 0x07);
	
	return ;
}

void put_bin(int num)              //二进制
{
	char a[2]="01";
	putchar(a[num]);

	return ;
}

void put_int_bin(int num)
{
	int i;
	for(i = 31; i>=0; i--)
		put_bin((num >> i) & 0x01);

	return ;
}

int main(void)
{
	int num;
	printf("请输入一个整数\n");
	scanf("%d",&num);
	printf("输出十六进制\n");
	put_int_hex(num);
	putchar(10);
	printf("输出八进制\n");
	put_int_oct(num);
	putchar(10);
	printf("输出二进制\n");
	put_int_bin(num);
	putchar(10); 
	
	return 0;
}
