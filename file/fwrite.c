#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char str[1024];
	char ch;
	int len;
	if(argc < 3)
	{
		printf("./a.out file1 file2\n");
		exit(-1);
	}
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w+");

	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(len = fread(str, 1, sizeof(str), fp1))
		fwrite(str, 1, len, fp2);
	rewind(fp2);
	while((ch = fgetc(fp2)) != EOF)
		fputc(ch, stdout);
	fclose(fp1);
	fclose(fp2);

	return 0;

}
