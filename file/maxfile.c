#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(void)
{
	FILE *fp;
	printf("%d\n", errno);
	fp = fopen("abc", "r");
	if(fp == NULL)
	{
		perror("fopen");
		printf("%s\n", strerror(errno));
		exit(0);
	}
	fclose(fp);

	return 0;
}
