#include <stdio.h>

void bar(int c, int d)
{
	printf("haha.............\n");

	return ;
}

int foo()
{
	int i;
	#if 0
	printf("<foo> *(&i + 1) = 0x%x\n", *(&i + 1)); 
	printf("<foo> *(&i + 2) = 0x%x\n", *(&i + 2)); 
	printf("<foo> *(&i + 3) = 0x%x\n", *(&i + 3)); 
	printf("<foo> *(&i + 4) = 0x%x\n", *(&i + 4)); 
	printf("<foo> *(&i + 5) = 0x%x\n", *(&i + 5)); 
	printf("<foo> *(&i + 6) = 0x%x\n", *(&i + 6)); 
	printf("<foo> *(&i + 7) = 0x%x\n", *(&i + 7)); 
	printf("<foo> *(&i + 8) = 0x%x\n", *(&i + 8)); 
	#endif

	printf(" i = %d\n", i);
	printf("<foo> &i = %p\n", &i);

//	*(&i + 4) = (int)bar;
	return ;
}

extern _start;

int main(void)
{
	int i;
	int *p;
	p = &i;
	*(&i - 12) = 100;
	printf("&i = %p\n", &i);
	printf("&i - 12 = %p\n", (&i - 12));
	foo();
	printf("&main = %p\n", &main);
	printf("&_start = %p\n", &_start);
	return 0;
}
