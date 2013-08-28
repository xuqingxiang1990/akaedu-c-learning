#nclude <stdio.h>
#include <time.h>
#define N 10
#define MAX 100

void init_array(int a[])
{
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++)
		a[i] = rand() % 100;
	
	
}

void print_array(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%-3d", a[i]);
	putchar(10);
}

void sweap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int a[], int len)
{
	int i, j;
	for(i = 1; i < len; i++)
		for( j = 0; j < len -i; j++)
			if(a[j] > a[j + 1])
				sweap(&a[j], &a[j + 1]);
}

void select_sort(int a[], int len)
{
	int i, j, min;
	for(i = 0; i < len; i++)
	{
		min = i;
		for(j = i + 1; j < len; j++)
			if(a[j] < a[min])
				min = j;
		sweap(&a[i], &a[min]);
	}
}

void insert_sort(int a[], int len)
{
	int i, j, tmp;
	for(i = 2; i <= len; i++)
	{
		tmp = a[i - 1];
		for(j = i - 2; j >= 0; j--)
			if(tmp < a[j])
				a[j + 1] = a[j];
			else
				break;
		a[j + 1] = tmp;
	}
}

void merge(int a[], int l, int m, int r)
{
	int i, j, k, b[r + 1];		
	for(i = l; i <= r; i++)
		b[i] = a[i];
	i = l, j = m + 1, k = l;
	while(i <= m && j <= r)
		if(b[i] < b[j])
			a[k++] = b[i++];
		else
			a[k++] = b[j++];
	while(i <= m)
		a[k++] = b[i++];
	while(j <= r)
		a[k++] = b[j++];
}

void merge_sort(int a[], int l, int r)
{
	int i, j, m;
	m = (l + r) / 2;
	if(l >= r)
		return ;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}

int pertition(int a[], int l, int r)
{
	int i, j;
	for(i = l + 1, j = l; i <= r; i++)
		if(a[i] < a[l])
			sweap(&a[i], &a[++j]);
	sweap(&a[j], &a[l]);
	return j;
}

void quick_sort(int a[], int l, int r)
{
	int i, j, m;
	if(l >= r)
		return ;
	m = pertition(a, l, r);
	quick_sort(a, l, m - 1);
	quick_sort(a, m + 1, r);
}

int search(int a[], int l, int r, int key)
{
	int m;
	m = (r + l) / 2;
	if(l > r)
		return 0;
	if(key > a[m])
		return search(a, m + 1, r, key);
	else if(key < a[m])
		return search(a, l, m - 1, key);
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
	printf("冒泡:\n");
	init_array(a);
	print_array(a);
	bubble_sort(a, N);
	print_array(a);

	printf("选择:\n");
	init_array(a);
	print_array(a);
	select_sort(a, N);
	print_array(a);

	printf("插入:\n");
	init_array(a);
	print_array(a);
	insert_sort(a, N);
	print_array(a);

	printf("归并:\n");
	init_array(a);
	print_array(a);
	merge_sort(a, 0, N - 1);
	print_array(a);

	printf("快速:\n");
	init_array(a);
	print_array(a);
	quick_sort(a, 0, N - 1);
	if(search(a, 0, N - 1, key))
		printf("find ok %d\n", key);
	else
		printf("sorry un find\n");
	print_array(a);


	return 0;
}
