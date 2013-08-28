#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
	int num;
	char path[100];
};

typedef struct record record_t;
record_t  a[1024], max;

void sort(record_t a[], int n)
{
	int i, j;
	record_t temp;
	for(i = 1; i < n; i++)
		for(j = 0; j < n -i; j++)
		{
			if(a[j].num < a[j + 1].num)
			{
				temp =	a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[1024];
	char *p;
	int  i = 0, j;
	int ret;
	if(argc < 2)
	{
		printf("./a.out file\n");
		exit(-1);
	}

	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	max.num = a[0].num;
	char nu[100];
	#if 1
	while(1)                                              // 方法一
	{
		ret = fscanf(fp, "%d %s", &a[i].num, a[i].path);
	//	ret = fscanf(fp, "%s %s %s %s %d %s %s %s", nu, nu, nu, nu,  &a[i].num, nu, nu, a[i].path);
		if(max.num < a[i].num)
			max = a[i];
		if(ret < 0)
			break;
		printf("%-2d %s\n", a[i].num, a[i].path);
		i++;
	}
	#endif

	#if 0
	while((fgets(str, sizeof(str), fp)) != NULL)                   //方法二 
	{
			a[i].num = atoi(strtok(str, "."));	
			strcpy(a[i].path, strtok(NULL,"\n"));
			if(a[max].num < a[i].num)
				max = i;
			i++;

	}
	#endif

	putchar(10);
	printf("排序后:\n");	
	sort(a, i);
	for(j = 0; j < i; j++)
		printf("%-2d %s\n", a[j].num, a[j].path);
	printf("maxline = <%d>   path = <%s>\n", max.num, max.path);
	fclose(fp);
	
	return 0;
}
