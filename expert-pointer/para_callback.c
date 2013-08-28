#include <stdio.h>

typedef void(*callback_t)(void *);

void cont_num(void *num)
{
	int i;
	for(i = 1; i <= (int)num; i++)
		printf("%d", i);
	putchar(10);
}


void say_hello(const char *str)
{
	printf("%s\n", str);
}

void repeat_three_times(callback_t f, void *para)
{
	f(para);
	f(para);
	f(para);
}

int main(void)
{
	repeat_three_times(say_hello, "hello akaedu");
	repeat_three_times(cont_num, (void *)4);

	return 0;
}
