#include <stdio.h>

int main(void)
{
	int m, n, s;
	int i;
	scanf("%d%d", &m, &n);
	for( i = 2; i <= m; i++)
		s = (s + n) % i;
	printf("%d\n", s + 1);

	return 0;
}
