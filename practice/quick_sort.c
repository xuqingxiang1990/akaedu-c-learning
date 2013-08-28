#include <stdio.h>
#include <time.h>
#define N 10
#define MAX 100

void init_digit(int a[])
{
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++)
		a[i] = rand() % MAX;
}

void print_digit(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	putchar(10);
}

void sweap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int position(int a[], int l, int r)
{
	int m, i, j, k;
	k = l;
	for(i = l + 1, j = l; i < r; i++)
		if(a[i] < a[l])
			sweap(&a[++j], &a[i]);
	sweap(&a[j], &a[l]);
	return j;
}

void quick_sort(int a[], int l, int r)
{
	int k; 
	if(l > r)
		return ;
	k = position(a, l, r);
	quick_sort(a, l, k - 1);
	quick_sort(a, k + 1, r);
}

void merge(int a[], int l, int m, int r)
{
	int  i, j, b[r + 1], k;
	for(i = l; i <= r; i++)
		b[i] = a[i];
	i = l, j = m + 1, k = l;
	while(i <= m && j <= r)
	{
		if(b[i] < b[j])
			a[k++] = b[i++];
		if(b[j] < b[i])
			a[k++] = b[j++];
	}
	while(i <= m)
		a[k++] = b[i++];
	while(j <= r)
		a[k++] = b[j++];
}

void merge_sort(int a[], int l, int r)
{
	int m;
	if(l >= r)
		return ;
	m = (l + r) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);

}

int main(void)
{
	int a[N];
	init_digit(a);
	print_digit(a);
	//quick_sort(a, 0, N - 1);
	merge_sort(a, 0, N - 1);
	print_digit(a);
	
	return 0;
}
