#include <stdio.h>
#include < string.h>

//char *my_strchr(char *s1, int ch)
int main(void)
{
	char s1[100], ch;
	scanf("%s", s1);
	scanf("%c",&ch);
	printf("%d\n", strchr(s1, ch));

	return 0;
}
