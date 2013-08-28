#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "student.h"

#if 1
struct student {
	char name[32];
	char cname[16];
	int age;
	char gender[4];
	char native[16];
	char tel[16];
	char qq[16];
	char email[1208];
	char hobby[1208];
};
#endif

typedef struct student stu_t;

stu_t stu[40];

void print_stu(stu_t *stu, int num)
{
	int i;
	for(i = 0; i < num; i++)
		printf(" %-14s %-8s %-7d  %-8s %-12s %-13s %-14s %-14s %-14s\n",
				stu[i + 1].name,
				stu[i + 1].cname, 
				stu[i + 1].age,
				stu[i + 1].gender,
				stu[i + 1].native,
				stu[i + 1].tel,
				stu[i + 1].qq, 
				stu[i + 1].email, 
				stu[i + 1].hobby);
}

int load_file(char *file)
{
	FILE *fp;
	char str[1024];
	int num = 0, i;
	int count = 0;
	char *p;
	fp = fopen(file, "r");

	while(fgets(str, sizeof(str), fp) != NULL)
	{
		
		num++;
		sscanf(str, "%s %s %d %s %s %s %s %s %s",
				stu[num].name,
				stu[num].cname,
				&stu[num].age,
				stu[num].gender,
				stu[num].native,
				stu[num].tel,
				stu[num].qq,
				stu[num].email,
				stu[num].hobby
				);

	}
	return num;

	fclose(fp);

	
}

int cmp_stu_age(const void *s1, const void *s2)
{
	return (*(stu_t *)s1).age - (*(stu_t *)s2).age;
}

int cmp_stu_str(const void *s1, const void *s2)
{
	return strcmp((*(stu_t *)s1).name , (*(stu_t *)s2).name);
}

char *my_scanf(char *str, int n)
{
	int len;
	fgets(str, n, stdin);
	len = strlen(str);
	str[len - 1] = '\0';
	return str;
}

void display(void)
{
	printf("**********************> wecomle to student system <*******************************************\n"); 
	printf("*************************> you can select <****************************************************\n");
	printf("****	   		1.查看学生信息：		请输入A                    ************\n\n"); 
	printf("****			2.学生信息按照姓名排序并输出：  请输入B			   ************\n\n");    
	printf("****			3.学生信息按照年龄排序:		请输入C                    ************\n\n");
	printf("****			4.查找学生（按照名字）:		请输入D                    ************\n\n");
	printf("****			5.查找学生（按照地区）:		请输入E                    ************\n\n");
	printf("****			6.查找学生爱好	:		请输入F                    ************\n\n");
	printf("****			7.退出系统请输入: #		       	                   ************\n\n");
	printf("***********************************************************************************************\n");

}

void seek_stu(char *str, int num)
{
	int i;
	int count = 0;
	for(i = 0; i < num; i++)
		if(strcmp(stu[i].name, str) == 0 || strcmp(stu[i].native, str) == 0 || strstr(stu[i].hobby, str) != NULL)
		{
				printf("%-14s %-8s %-7d  %-8s %-12s %-13s %-14s %-14s %-14s\n",
				stu[i].name,
				stu[i].cname, 
				stu[i].age,
				stu[i].gender,
				stu[i].native,
				stu[i].tel,
				stu[i].qq, 
				stu[i].email, 
				stu[i].hobby);

				count++;

		}

	if(count == 0)
			printf("Sorry The system NO  Data \n");
		
}

int main(int argc, char *argv[])
{
	
	int ret, len;
	char ch;
	char str1[20], str2[20];	
	char temp, temp1;
	putchar(10);
	display();
	if(argc < 2)
	{
		printf("./a.out file\n");
		exit(-1);
	}
	ret = load_file(argv[1]);
	printf("请选择操作：\n");
	while(1)
	{
		ch = getchar();
		switch(ch)
		{
			case 'A':
				print_stu(stu, ret);
				display();
				printf("请继续选择操作\n");
				break;
			case 'B':
				qsort(stu, ret + 1, sizeof(stu_t), cmp_stu_str);
				print_stu(stu, ret);
				display();
				printf("请继续选择操作\n");
				break;
			case 'C':
				qsort(stu, ret + 1, sizeof(stu_t), cmp_stu_age);
				print_stu(stu, ret);
				display();
				printf("请继续选择操作\n");
				break;
			case 'D':
				printf("请输入查询的姓名：\n");
				my_scanf(str1, sizeof(str1));
				fgets(str1, sizeof(str1), stdin);
				len = strlen(str1);
				str1[len - 1] = '\0';
				seek_stu(str1 ,ret);
				display();
				printf("请继续选择操作\n");
				break;
			case 'E':
				printf("请输入查询的地区：\n");
				my_scanf(str2, sizeof(str2));
				fgets(str2, sizeof(str2), stdin);
				len = strlen(str2);
				str2[len - 1] = '\0';
				seek_stu(str2 ,ret);
				display();
				printf("请继续选择操作\n");
				break;
			case 'F':
				printf("请输入查询个人爱好\n");
				my_scanf(str2, sizeof(str2));
				fgets(str2, sizeof(str2), stdin);
				len = strlen(str2);
				str2[len - 1] = '\0';
				seek_stu(str2 ,ret);
				display();
				printf("请继续选择操作\n");
				break;


		}
		if(ch == '#')
		{
			printf("欢迎下次再来\n");
			break;
		}
	}
	
	return 0;

}
