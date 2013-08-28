#include <stdio.h>

union s5 {

//	char *b1;
//	int *b2;
	double b3;
};

enum s4 {
	a1, a2, a3, a4, a5

};

struct s1 {
	int *w;
	char s3;
	char *s2;
};
int main(void)
{
	char *p[100];
	double q;
	printf("%d\n%d\n%d\n%d\n",sizeof(*p), sizeof(q), sizeof(struct s1), sizeof(union s5));

	return 0;
}
