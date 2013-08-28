#include <stdio.h>
#include <stdlib.h>

void _Assert(char *mesg);

#define _STR(x)_VAL(x)
#define _VAL(x)#x
#define assert(test) ((test)?(void)0\
	:_Assert(__FILE__":"_VAL(__LINE__)""#test))

void _Assert(char *mesg)
{
//	fputs(mesg, stderr);
	printf("%s\n", mesg);
	printf("--assertion failed\n");
//fputs("--assertion failed\n", stderr);
	abort();
}


#pragma pack(1)

struct str {
	
	int a;
	char b;
	int c;
};

int main(void)
{
	assert(2 < 3);
	
	printf("struct str sizeof = %d\n", sizeof(struct str));
	printf("&b = %p\n", &(((struct str *)0)->b));
	printf("%s\n", _VAL(2));

	return 0;
}
