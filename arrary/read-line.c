#include <stdio.h>

int main(void)
{
	char ch;
	system("stty raw");
	printf("do you want to continue?y\n");
	do
	{
		ch = getchar();
		printf("ch = %c (0x%x) \r\n", ch, ch);

	} while(1);

	if(ch = 'y')
		printf("ok, continue\n");
	else
		printf("good bye!\n");
	system("stty -raw");

	return 0;
}
