#include <stdio.h>
#include <string.h>

int main(void)              
{
	int len, s = 1;
	char str[100], *p;
	fgets(str, 100, stdin);
	len = strlen(str);
	str[len - 1] = '\0';
	p = str;
	printf("%s\n", p);

	#if 0                    //163邮箱判定
	while(*p)
	{
		switch(s)
		{
			case 0:
				printf("NO\n");
				return 0;
			case 1:
				if(isalpha(*p))
					s = 2;
				else
					s = 0;
				break;
			case 2:
				if(*p == '@')
					s = 3;
				else if(isalpha(*p))
					s = 2;
				else
					s = 0;
				break;
			case 3:
				if(*p == '1')
					s = 4;
				else
					s = 0;
				break;
			case 4:
				if(*p == '6')
					s = 5;
				else
					s = 0;
				break;
			case 5:
				if(*p == '3')
					s = 6;
				else
					s = 0;
				break;
			case 6:
				if(*p == '.')
					s = 7;
				else
					s = 0;
				break;
			case 7:
				if(*p == 'c')
					s = 8;
				else
					s = 0;
				break;
			case 8:
				if(*p == 'o')
					s = 9;
				else
					s = 0;
				break;
			case 9:
				if(*p == 'm')
					s == 10;
				break;

		}

		p++;
	}
	printf("%d\n", s);
	if(s == 9)
		printf("YES\n");
	#endif


	#if 1                           //去除注释
	while(*p)
	{
		switch(s)
		{
			case 1:
				if(*p != '/')
					putchar(*p);
				else
					s = 2;
				break;
			case 2:
				if(*p == '/')
					putchar('/');
				
				else if(*p == '*')
					s = 3;
				else 
				{
					putchar('/');
					putchar(*p);
					s = 1;
				}
				break;
			case 3:
				if(*p == '*')
					s = 4;
				else
					s = 3;
				break;
			case 4:
				if(*p == '/')
					s = 1;
				else
					s = 3;
				break;
		}
		p++;
	}
	#endif


	return 0;
}

