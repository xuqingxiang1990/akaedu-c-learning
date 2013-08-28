#include <stdio.h>

struct STU {
	char fn[10];
	int sex;
};

typedef struct STU stu_t;

stu_t stu[20] = {
					{"xu", 22},
					{"teacher", 32},
					{"student", 21},
					{"good", 24}
				};

char *names[] =
{
	"xu",
	"qing",
	"xiang",
	"ni",
	"hao"
};

int cmp_char(const void *s1, const void *s2)
{
	return strcmp(*(char **)s1, *(char **)s2);
}

int comper_int1(const void *s1, const void *s2)
{
	return *(int *)s1 - *(int * )s2; 
}

int comper_int2(const void *s1, const void *s2)
{
	return *(int *)s2 - *(int *)s1 ; 
}

int cmp_stu_int(const void *s1, const void *s2)
{
	return (*(stu_t *)s1).sex - (*(stu_t *)s2).sex;	
}

int cmp_stu_char(const void *s1, const void *s2)
{	
	return strcmp((*(stu_t *)s1).fn, (*(stu_t *)s2).fn);
}

int main(void)
{	
	int i;
	int a[10] = {23, 2, 56, 12, 345, 67, 123, 5, 22, 90};
	for(i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar(10);
	putchar(10);
	printf("***************** 数字排序 升序**************************\n");
	qsort(a, 10, 4, comper_int1);
	for(i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar(10);
	putchar(10);

	printf("***************** 数字排序 降序**************************\n");
	qsort(a, 10, 4, comper_int2);
	for(i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar(10);
	putchar(10);

	printf("*****************  字符排序 ******************************\n");
	for(i = 0; i < 5; i++)
		printf("names[%d] = %s\n", i, names[i]);
	putchar(10);
	putchar(10);
	qsort(names, 5, 4, cmp_char);
	for(i = 0; i < 5; i++)
		printf("names[%d] = %s\n", i, names[i]);

	printf("***************** 结构体排序 ****************************\n");
	for(i = 0; i < 4; i++)
		printf("name[%d] = %-8s  sex = %-2d\n", i, stu[i].fn, stu[i].sex);
	qsort(stu, 4, sizeof(stu_t), cmp_stu_int);
	putchar(10);
	for(i = 0; i < 4; i++)
		printf("name[%d] = %-8s  sex = %-2d\n", i, stu[i].fn, stu[i].sex);
	putchar(10);

	qsort(stu, 4, sizeof(stu_t), cmp_stu_char);
	for(i = 0; i < 4; i++)
		printf("name[%d] = %-8s  sex = %-2d\n", i, stu[i].fn, stu[i].sex);


	return 0;
}
