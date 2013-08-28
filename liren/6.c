#include<stdio.h>
int main()
{
				char s[100],ch;
				int i=0,j;
				while((s[i++]=getchar())!='\n');
//				s[i]='\0';
				for(j=0;j<i;j++)
								printf("%c ",s[j]);
				return 0;
}
