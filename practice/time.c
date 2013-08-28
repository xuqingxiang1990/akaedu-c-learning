#include <stdio.h>

int main(void)
{
	int hour = 23, minute = 59, second = 50;
	while(1)
	{
		second++;
		if(second == 60)
		{
			second = 0;
			minute++;
			if(minute == 60)
			{
				minute = 0;
				hour++;
				if(hour == 24)
				{
					hour == 0;
				}
			}
		}
		printf("%02d:%02d:%02d\n", hour, minute, second);
		fflush(stdout);
		sleep(1);
	}

	return 0;
}
