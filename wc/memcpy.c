#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[120]  = "hello world\n";
	char buf1[120]  = "hello world\n";
	memmove(buf + 1 ,buf, 13);
	printf("%s", buf);
	memcpy(buf1 + 1 , buf1, 13);
	printf("%s", buf);

	return 0;
}
