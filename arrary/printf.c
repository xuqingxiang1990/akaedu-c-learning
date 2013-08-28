#include <stdio.h>
#define N 1

int main(void)
{
	char buf1[N];
	char buf2[N];
	fgets(buf1, N+16,stdin);

	printf("buf = <%s>\n", buf1);

	printf("hello");

	scanf("%s", buf2);
	printf("printf <%s>\n", buf2);

	while(1);

	return 0;
}
