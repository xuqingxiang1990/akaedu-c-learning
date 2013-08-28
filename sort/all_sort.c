#include <stdio.h>
#include <time.h>
#define N 10
#define MAX 100

void init_data(int a[])
{
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++)
		a[i] = rand() % MAX;
}

void print_data(int a[], int len)
{
	int i;
	for( i = 0; i < len; i++)
		printf("%-3d", a[i]);
	putchar(10);
}

void sweap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a  = *b;
	*b  = tmp;
}

void bubble(int a[], int len)
{
	int i, j;
	for(i = 1; i < len; i++)
		for(j = 0; j < len - i; j++)
			if(a[j] > a[j + 1])
				sweap(&a[j], &a[j + 1]);
}

void select_sort(int a[], int len)
{
	int i, j;
	int min;
	for(i = 0; i < len; i++)
	{	
		min = i;	
		for(j = i + 1; j < len; j++)
			if(a[min] > a[j])
				min = j;
		sweap(&a[min], &a[i]);
	}
}

void insert_sort(int a[], int len)
{
	int i, j, tmp;
	for(i = 2; i <= len; i++)
	{
		tmp = a[i - 1];
		for(j = i - 2; j >= 0; j--)
			if(a[j] > tmp)
				a[j + 1] = a[j];
			else
				break;
		a[j + 1] = tmp;
	}
}

void merge(int a[], int l, int r)
{
	int m, i, j, b[r + 1], k;
	m = (l + r) / 2;
	for(i = l ; i <= r; i++)
		b[i] = a[i];
	i = l , j = m + 1; 
	k = l;
	while(i <= m && j <= r)
		if(b[i] < b[j])
			a[k++] = b[i++];
		else if(b[i] > b[j])
			a[k++] = b[j++];
	while(i <= m)
		a[k++] = b[i++];
	while(j <= r)
		a[k++] = b[j++];

}

void merge_sort(int a[], int l, int r)
{
	int m;
	m = (l + r) / 2;
	if( l >= r)
		return ;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, r);
}

int position(int a[], int l, int r)
{
	int i, j;
	for( i = l + 1, j = l; i <= r; i++)
		if(a[i] < a[l])
			sweap(&a[i], &a[++j]);
	sweap(&a[j], &a[l]);

	return j;
}

void quick_sort(int a[], int l, int r)
{
	int m;
	if(l > r)
		return ;
	m = position(a, l, r);
	quick_sort(a, l, m - 1);
	quick_sort(a, m + 1, r);
}

int binary(int a[], int l, int r, int key)
{
	int m;
	m = (l + r) / 2;
	if( l > r)
		return 0;
	if(key > a[m])
		return binary(a, m + 1, r, key);
	else if(key < a[m])
		return binary(a, l, m - 1, key);
	else
		return 1;
	#if 0
	int m;
	while(l <= r)
	{
		m = (l + r) / 2;
		if(key > a[m])
			l = m + 1;
		else if(key < a[m])
			r = m - 1;
		else 
			return 1;
	}

	return 0;
	#endif
}

int main(void)
{
	int a[N];
	int key = 50;
	init_data(a);
	print_data(a, N);
	//bubble(a, N);
	//select_sort(a, N);
	//insert_sort(a, N);
	//merge_sort(a, 0, N - 1);
	quick_sort(a, 0, N - 1);
	print_data(a, N);
	if(binary(a, 0, N - 1, key))
		printf("Yes %d\n", key);
	else
		printf("NO\n");

	return 0;
}
