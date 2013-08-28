#include<stdio.h>
#include<string.h>
void print_str(char*s)
{
  char *p;
  int len;
  len=strlen(s);
  for(p=s+len-1;p>=s;p--)
    printf("%c",*p);
  printf("\n");
}
int main()
{
   char str[100];
   scanf("%s",str);
   print_str(str);
   return 0;
}
