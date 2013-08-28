#include <stdio.h>

typedef void(*F)(char *);         // void(*)(char *) F;
typedef void FP(char *);

void say_hello(const char *str)
{
	printf("%s\n", str); 
}

int main(void)
{
	void(*f)(const char *) ;
	int a;
	F f2;
	FP *f3;

	f3 = say_hello;
	f3("good body");

	f2 = say_hello;
	f2("gxinag");

	f = say_hello;
	printf("f = %p\n", f);
	printf("say_hello = %p\n", say_hello);
	f("hello");
	a = 0x8048445;
	((void(*)(char *))a)("akaedu");

	return 0;
}
