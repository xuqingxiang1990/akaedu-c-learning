#include <stdio.h>
#include <string.h>


int add(int a, int b);
int div(int a, int b);
int sub(int a, int b);


struct operation {

	char name[32];
	int (*fp)(int a, int b);
};

typedef struct operation op_t;

op_t ops[] = 
{
	{"add", add},
	{"sub", sub},
	{"div", div},
};

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int div(int a, int b)
{
	return a * b;
}


#if 1
void del_space(char *str)
{
	int flag = 0;                       //     xu    qing   xing
	char *p, *q;
	int i = 0;
	p = q = str;

	while(*p)
	{
		if(*p != ' ')
		{
			flag = 1;
			*q++ = *p;
			i++;
		}
		if(flag == 1 && *p == ' ')
		{
			flag = 0;
			*q++ = *p;
			i++;
		}
		p++;

	}
	*q = *p;
	return ;


	#if 0
	for( ; *p != '\0'; p++)
	{
		if(*p == ' ')
			flag = 0;
		else if(flag == 0)
		{
			flag = 1;
			putchar(' ');
			putchar(*p);
		}
		else
			putchar(*p);
	}
	#endif



		#if 0
		switch(flag)
		{
			case 1:
				if(*p == ' ')
				{
					flag = 2;
					putchar(' ');
				}
				else if(*p != ' ')
				{
					putchar(*p);
				}
				break;
			case 2:
				if(*p != ' ')
				{
					flag = 1;
					putchar(*p);
				}
				else if(*p == ' ')
					flag = 2;
				break;
				
		}
	}
		#endif
}
#endif


int parse(char *str, char *argv[])
{
	char *p;
	int i = 0, flag = 0;
	p = str;
	while(*p)
	{
		if(*p != ' ' && flag == 0 && *p != '\n')
		{
			argv[i] = p; 
			i++;
			flag = 1;
		}
		if((*p == ' ' || *p == '\n') && flag == 1) 
		{
			*p = '\0';
			flag = 0;
			
		}
		p++;
	}
	argv[i] = NULL;
	return i;
}

int main(void)
{
	char str[64];
	int argc, i = 0, len;
	char *argv[10];
	int ret = 0;
	printf("$$:");
	fgets(str, 64, stdin);
	len = strlen(str);
	str[len - 1] = '\0';
	del_space(str);
	argc = parse(str, argv);
	for(i = 0; i < sizeof(ops) / sizeof(ops[0]); i++)
	{
		if(strcmp(argv[0], ops[i].name) == 0)
		{
			ret =	ops[i].fp(atoi(argv[1]),atoi(argv[2]));
			printf("ret = %d\n", ret);
		}
		
	}
	

	#if 0
	if(strcmp(argv[0], "add") == 0)
		printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
	if(strcmp(argv[0], "sub") == 0)
		printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
	#endif

	printf("argc = %d\n", argc);
	for(i = 0; i < argc; i++)
		printf("argv[%d] = <%s>\n", i, argv[i]);


	return 0;
}
