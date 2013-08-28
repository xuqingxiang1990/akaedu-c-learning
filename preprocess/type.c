#include <stdio.h>
#define myprint(x) printf(#x" = %d\n", x)
#define myprintf(x) printf(#x" = %f\n", x)
#define myprintd(x) printf(#x" = %lf\n", x)
#define FUNC_TYPE(type)  \
	type type##_add(type a, type b) \
	{    \
		return a + b;    \
	}  

FUNC_TYPE(int);
#if 0
FUNC_TYPE(float);
FUNC_TYPE(double);

#endif

int main(void)
{
	int a = 100;
	int b = 200;
	int c = 300;

//	myprint(FUNC_TYPE(int, a, b));
	//myprintf(b);
//	myprintd(c);

	return 0;
}
