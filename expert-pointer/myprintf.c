#include <stdio.h>
#include <stdarg.h>

char buf[100];
int myprintf(const char *format, ...)
{
	char ch;
	int value;
	char *p;
	int *ap;

	ap = (int *)&format;
	ap++;
	printf("&format = %p \n", &format);

	while((ch = *format++) != '\0') 
	{
		if(ch == '%')
		{
			ch = *format++;
			switch(ch)
			{
				case 'd':
					value = (int)*ap++;
					sprintf(buf, "%d", value);
					//printf("%s", buf);
					fputs(buf, stdout);
					break;
				case 's':
					p = (char *)*ap++;
					//printf("%s", p);
					fputs(p, stdout);
					break;
				case 'c':
					putchar(*ap++);
				default:
					break;
			}
			continue;
		}
		putchar(ch);
	}

	return 0;
}


int main(void)
{
	int a = 34;
	char str[] = "hello ";
	char ch = 'W';
	myprintf("a = %d, str = %s, ch = %c\n", a, str, ch);
	myprintf("ch = %c str = %s, a = %d\n", ch, str, a);

	return 0;
}
