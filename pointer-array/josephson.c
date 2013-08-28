#include <stdio.h>

int josephson(int n, int m)
{
	int i, j, p, a[1000], count;
	for(i = 0; i < n; i++)
		a[i] = i + 1;
	p = 0;
	for(i = 0; i < n; i++)
	{
		for(count = 0; count < m; count++)
		{
			while(a[p] == 0)
				p = (p + 1) % n;
			p = (p + 1) % n;
		}
		
		p = p -1;

		if(p < 0)
			p = n -1;
		if(i == n -1)
			printf("%d\n", a[p]);
		a[p] = 0;
			
	}
}

int main(void)
{
	int n, m, s = 0;
	scanf("%d%d", &n, &m);
	josephson(n, m);

	return 0;
}
