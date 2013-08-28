#include <stdio.h>
int main(void)
{
	unsigned char c = 0xfc;
	unsigned int i = ~c;
	printf("0x%x\n", i);

	return 0;
}
