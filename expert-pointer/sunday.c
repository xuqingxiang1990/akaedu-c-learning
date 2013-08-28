#include <stdio.h>
#include <string.h>


char buf[20];

int a = 10;

static const char *msg[] = { "sunday", "monday", "tuesday", "wednesday"};


char *get_a_day(int idx)
{
	strcpy(buf, msg[idx]);
	return buf;
}

int main(void)
{	
//	int a; 
	printf("%d\n", a);
	printf("%s %s \n", get_a_day(0), get_a_day(1));
	printf("%s %s \n", get_a_day(2), get_a_day(3));

	return 0;
}
