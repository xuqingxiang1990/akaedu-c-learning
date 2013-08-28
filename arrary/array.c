#include <stdio.h>

int main(void)
{
	char str[]="xu qing xiang ni hao";
	char buf[100];
	sprintf(buf, "%d %s", 100, "ni hao");
	puts(buf);
	printf("%.5s\n", str);
	printf("%-5.4s\t\n", str);
	printf("%-12.9s %4d %-11.13s\n", "li cheng", 22, "heilongjiang");
	printf("%-12.9s %4d %-11.8s\n", "zhangchenyang", 21, "henan");
	printf("%-12.9s %4d %-11.8s\n", "xu qing xiang ", 23, "henan");

	return 0;
}
