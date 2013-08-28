#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2, *fp3;
	char ch;
	
	if(argc < 2)
	{
		printf("./a.out command\n");
		exit(-1);
	}
	if(strcmp(argv[1], "cp") == 0)
	{
		fp1 = fopen("cp.txt", "r");

		while((ch = fgetc(fp1)) != EOF)
			fputc(ch, stdout);
		fclose(fp1);
	}

	if(strcmp(argv[1], "ls") == 0)
	{
		fp2 = fopen("ls.txt", "r");

		while((ch = fgetc(fp2)) != EOF)
			fputc(ch, stdout);
		fclose(fp2);
	}

	if(strcmp(argv[1], "mv") == 0)
	{
		fp3 = fopen("mv.txt", "r");

		while((ch = fgetc(fp3)) != EOF)
			fputc(ch, stdout);
		fclose(fp3);
	}

	return 0;	
}
