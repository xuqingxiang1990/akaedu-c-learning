#include <stdio.h>
#include <string.h>
int str(char *a,char *b)
{
  char *p;
  if(p=strstr(a,b))
	return p-a; 
  return -1;
}
int main()
{
  printf("%d\n",str("abcde","de"));
  return 0;
}
