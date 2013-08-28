#include <stdio.h>

int _func_ ;
void myfunc(void)
{
	printf("%s\n", _func_);

}

int main(void)
{	
	myfunc();
	printf("%s\n", _func_);

	return 0;
}
