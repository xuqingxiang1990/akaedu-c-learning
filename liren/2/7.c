#include<stdio.h>
int main()
{
  char s[]="hsjodi",*p;
  for(p=&s[5];p>=s;p--)
  --*p;
  puts(s);
  return 0;
}
