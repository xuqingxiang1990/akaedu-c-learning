#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[100];
	int i, len, j;
	
	fgets(a, sizeof(a), stdin)
	len = strlen(a);
	a[len - 1] = '\0';
	int k = 0, temp;
	while(k < len)
	{
		i = j = k;
		while(a[j]!=' ' && a[j]!='\0')
			j++;
		k = j + 1;
		j--;
		for(; i < j; i++, j--)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	printf("%s\n", a);
	}

	return 0;

}
