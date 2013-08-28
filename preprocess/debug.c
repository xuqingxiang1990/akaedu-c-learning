#include <stdio.h>
#define MK_ID(n) i##n
#define GENERIC_MAX(type)  \
type type##_add(type a, type b) \
{ \
	return a + b; \
}\

#define PI 3.1415
#define PWO_PI (2*PI)
#define DEBUG(x) printf("<%s>@<%s> line:%d " #x " = %d\n", __func__, __FILE__, __LINE__, x)

void mytestf(void)
{
	int i = 100;

	DEBUG(i);
	
	return ;
}

int main(void)
{
	int i = 100;
	int MK_ID(1), MK_ID(2), MK_ID(3);

	DEBUG(i);

	GENERIC_MAX(int);	

	GENERIC_MAX(float);	

	GENERIC_MAX(double);	
	printf("%d\n", PWO_PI);
	return 0;
}
