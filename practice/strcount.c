#include <stdio.h>
#include <string.h>

char *myscanf(char *str, int n)
{
	int len;
	fgets(str, n, stdin);
	len = strlen(str);
	str[len -1] = '\0';
	return str;
}

int strcount(char *str1, char *str2)
{
	int counter = 0, len;
	char *p;
	len = strlen(str2);
	while(1)
	{
		p = strstr(str1, str2);
		if(p == NULL)
			break;
		p = p + len;
		str1 = p;
		counter++;
	}
	return counter;
	#if 0
	while((p = strstr(str1, str2)) != NULL)
	{
		counter++;
		str1 = p;
	}
	return counter;
	#endif
}

int main(void)
{
	char str1[100], str2[100];
	myscanf(str1, sizeof(str1));
	myscanf(str2, sizeof(str2));
	printf("counter = %d\n", strcount(str1, str2));
//	strcount(str1, str2);	

	return 0;
}
