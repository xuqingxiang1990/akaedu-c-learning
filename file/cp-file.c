#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char ch;
	char buf[1024];
	char str[10];
	int len;

	#if 0
	printf("拷贝之前：\n");	
	fp1 = fopen("argv[1]", "w+");
	fp2 = fopen("argv[2]", "w+");
	while(fgets(buf, sizeof(buf), fp1) != EOF)
		fputs(buf, fp1);
	fclose(fp1);
	fclose(fp2);
	#endif
	if(argc < 3)
	{
		printf("./out dest src\n");
		exit(0);
	}

	fp1 = fopen(argv[1], "a");
	fp2 = fopen(argv[2], "r");
	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(len = fread(buf, 1, sizeof(str)*10, fp2))
	{
		printf("len = %d\n", len);
		fwrite(buf, 1, len, fp1);
	}
	

	#if 0
	while(fgets(buf, sizeof(buf), fp2))
		fputs(buf, fp1);
	#endif
	fclose(fp1);
	fclose(fp2);

	#if 1
	printf("拷贝之后:\n");
	fp1 = fopen("a.txt", "r");
	fp2 = fopen("b.txt", "r");
	while((ch = fgetc(fp1)) != EOF)
		fputc(ch, stdout);	
	while((ch = fgetc(fp2)) != EOF)
		fputc(ch, stdout);	
	fclose(fp1);
	fclose(fp2);
	#endif

	return 0;

}
