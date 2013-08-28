#include <stdio.h>
#include <string.h>

typedef struct {
	int num;
	char msg[20];
}unit_t;

#if 0
unit_t set_unit(unit_t p)
{
	p.num = 3;
	strcpy(p.msg, "hello akaedu");
	return p;
}
#endif

void set_unit(unit_t *p)
{
	if(p == NULL)
		return ;
	p -> num = 3;
	strcpy(p -> msg, "hello akaedu");
	
}

int main(void)
{
	unit_t u;

//	u = set_unit(u);
	set_unit(&u);
	printf("%d %s\n", u.num, u.msg);

	return 0;
}
