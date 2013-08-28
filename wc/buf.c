#include <stdio.h>
#include <unistd.h>

int main(void)
{
	while(1)
	{
		printf("1");
		usleep(10000);
	}

	return 0;
}
