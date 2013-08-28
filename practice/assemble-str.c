#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100] = "hello", str2[100] = "akaedu";  
	char str[100];
	int i = 0, j = 0;
	int k = 0, len1, len2, len;
	
	#if 0
	while(str1[i] && str2[j])
	{
		if(str1[i] < str2[j])
			str[k++] = str1[i++];
		else
			str[k++] = str2[j++];
	}
	while(str1[i])
		str[k++] = str1[i++];
	while(str2[j])
		str[k++] = str2[j++];
	printf("%s\n", str);
	
	#endif


	#if 1
	len1 = strlen(str1);
	len2 = strlen(str2);
	len = (len1 < len2) ? len1 : len2;
	printf("%d\n", len);
	while(str1[i] && str2[j])
	{
		if(str1[i] > str2[j])
		{
			str[k] = str2[i++];
			str[k + 1] = str1[j++];
			k++;
		}
		else 
		{
			str[k] = str1[i++];
			str[k + 1] = str2[j++];
			k++;
		}
		k++;

	}
	while(str1[i])
		str[k++] = str1[i++];
	while(str2[j])
		str[k++] = str2[j++];
	str[k] = '\0';
	printf("%s\n", str);
	#endif

	return 0;
}
