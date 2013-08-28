#include <stdio.h>

#define OFSIZE(x) (&((struct str1 *)0x0)->x)

struct str{

	char a;
	short b;
	int c;
	char d;
}__attribute__((packed)) s;

#pragma pack(2)
struct str1{

	char a;
	short b;
	int c;
	char d;
} s1;

int main(void)
{
	static int f = 0;

	printf("%p \n", OFSIZE(b));

	printf(" sizeof(struct) = %d\n", sizeof(s));
	printf(" sizeof(struct) = %d\n", sizeof(s1));

	printf(" &a = %p\n", &((struct str *)0)->a);
	printf(" &b = %p\n", &((struct str *)0)->b);
	printf(" &c = %p\n", &((struct str *)0)->c);
	printf(" &d = %p\n", &((struct str *)0)->d);
	int e = 0;	
	return 0;
}
