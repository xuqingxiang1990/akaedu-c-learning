#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	char buf[1024];
	int len;

	fp = fopen("abc", "w");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	#if 0
	while(len = fread(buf, 1,sizeof(buf), stdin))
	{
		printf("%d\n", len);
		fwrite(buf, 1, len, fp);

	}
	#endif
	len = fread(buf, sizeof(buf), 1, stdin);
		printf("%d\n", len);
		fwrite(buf, sizeof(buf), 1, fp);

	fclose(fp);

	return 0;
}
