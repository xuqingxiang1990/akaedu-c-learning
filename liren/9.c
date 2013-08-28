#include<stdio.h>
#include<string.h>
int count_word(char*s)
{
  int count=0,flag=1;
  char *p;
  for(p=s;*p!=0;p++)
  {
	switch(flag)
	{
	  case 1:
		if(*p==' ')
		  flag=2;
		break;
	  case 2:
		if(*p==' ')
		  flag=2;
		else
		{
		  count++;
		  flag=1;
		}
		break;
	}
  }
  return count;
}
int main()
{
  char p[100];
  int len;
  fgets(p,sizeof(p),stdin);
  len=strlen(p);
  p[len-1]='\0';
  printf("%d\n",count_word(p));
  return 0;
}
