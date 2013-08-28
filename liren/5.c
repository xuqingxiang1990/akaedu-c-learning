#include<stdio.h>
void print_kongge(char*str)
{
		char*p;
		int s=1;
		/*  for(p=str;*p!=0;p++)
			{
			if(*p==' ')
			s=0;
			else if(s==0)
			{
			putchar(' ');
			putchar(*p);
			s=1;
			}
			else
			putchar(*p);
			}*/
		for(p=str;*p!=0;p++)
		{
				switch(s)
				{
						case 1:
								if(*p==' ')
										s=2;
								else
										putchar(*p);
								break;
						case 2:
								if(*p==' ')
										s=2;
								else
								{
										putchar(' ');
										putchar(*p);
										s=1;
								}
								break;
				}
		}
}
int main()
{
	  char s[100]="     xu      qing      xiang       ni    hao";
		print_kongge(s);
   	putchar(10);
		return 0;
}
