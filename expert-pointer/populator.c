#include <stdio.h>
#include <string.h>

struct STU {
	char name[10];
	int sex;
};

typedef struct STU unit_t;

void set_unit(unit_t *p)
{
	if(p == NULL)
		return ;
	p->sex = 20;
	strcpy(p -> name, "hello akaedu");

}

int main(void)
{
	unit_t stu;

	set_unit(&stu);
	printf("%d %s\n", stu.sex, stu.name);

	return 0;
}
