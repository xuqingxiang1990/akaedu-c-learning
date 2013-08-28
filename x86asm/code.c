#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argrv[])
{
	char *str = "xuqingxiang";
	char pass[15];
	printf("Please input the passwd:\n");
	gets(pass);
	if(strcmp(pass, str) == 0)
		printf("Login succeed!\n");
	else
	{
		printf("Passwd incorrect!\n");
		exit(0);
	}
	
	return 0;
}
