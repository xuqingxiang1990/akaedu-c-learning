#include<stdio.h>
int read_line(char a[])
{
  int i=0;
  char ch;
  while((ch=getchar())!='\n')
   a[i++]=ch;
  a[i]='\0';
  return i;

}

int main()
{
  char s[100];
  int n;
  scanf("%s",s);
  printf("%d\n",read_line(s));
  return 0;

}
