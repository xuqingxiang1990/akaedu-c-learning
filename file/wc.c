#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char ch;
	char buf[1024], str[1024][10];
	int len, flag, counter = 0;
	int j, i = 0;

	if(argc < 3)
	{
		printf("./a.out file1 file2\n");
		exit(-1);
	}

	fp1 = fopen(argv[1], "r+");
	fp2 = fopen(argv[2], "w+");

	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while((ch = fgetc(fp1)) != EOF)
	{
		char word[26];
		if(isalpha(ch))
		{
			word[i++] = ch;
			flag = 1;
		}
		if(!isalpha(ch) && flag == 1)
		{
			word[i] = '\0';
			strcpy(str[counter], word);
			counter++;
			i = 0;
			flag = 0;
		}
	}

	int num1 = 0, num2 = 0;
	for(i = 0; i < counter; i++)
		if(strcmp("she", str[i]) == 0 || strcmp("She", str[i]) == 0)
			num1++;
		else if(strcmp("like", str[i]) == 0 || strcmp("Like", str[i]) == 0)
			num2++;
	fprintf(fp2, "she  num is = %-3d\nlike num is = %-3d\n", num1, num2);
	rewind(fp2);
	while(len = fread(buf, 1, sizeof(buf), fp2))
		fwrite(buf, 1, len, stdout);
	fclose(fp1);
	fclose(fp2);

	return 0;
}
