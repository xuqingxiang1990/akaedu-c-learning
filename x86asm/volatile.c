#include <stdio.h>

volatile unsigned char recv;
volatile unsigned char send;

unsigned char buf[3];

static a;
int main(void)
{
struct str {
	int a;
	char b;
	int c;
} stu;


	buf[0] = recv;
	buf[1] = recv;
	buf[2] = recv;
	send = ~buf[0];
	send = ~buf[1];
	send = ~buf[2];
	printf("&struct str = %p\n", &stu);
	printf("&a = %p\n", &a);
	return 0;
}

