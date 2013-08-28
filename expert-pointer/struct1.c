#include <stdio.h>
#include <string.h>

typedef struct {
	int sex;
	char name[10];
}unit_t;

void set_unit(unit_t *p)
{
	if(p == NULL)
		return ;
	p -> sex = 100;
	strcpy(p -> name, "akaedu");
}

int main(void)
{
	unit_t u;
	set_unit(&u);
	printf("sex = %d\n name = %s\n", u.sex,u.name);

	return 0;
}
