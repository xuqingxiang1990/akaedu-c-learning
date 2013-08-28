#include <stdio.h>
#define MAX(a, b) ((a > b)?(a):(b))
#define TOUPPER(c) ('a'<=(c)&&(c)<='z')?(c)-'a'+'A':(c)

int main(void)
{
	char ch = 'q';
	printf("MAX = %d\n", MAX(MAX(4, 5), 3));
	printf("TOUPPER = %c\n", TOUPPER(w));

	return 0;
}
