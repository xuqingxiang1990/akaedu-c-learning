#include<stdio.h>

int strlen(const char *s)
{
  int n;
  for(n=0;*s!='\0';s++)
   n++;
   return n;
}

int main()
{
  char a[10];
  scanf("%s",a);
  printf("%d\n",strlen(a));
  return 0;
}
