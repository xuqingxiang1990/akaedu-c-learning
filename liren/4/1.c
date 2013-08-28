#include<stdio.h>
char*my_strstr(char*s1,char*s2)
{
  char *p,*q,*m;
  for(p=s1;*p!='\0';p++)
  {
    m=p;
	for(q=s2;(*q==*p)&&(*p!='\0')&&(*q!='\0');p++,q++);
	if(*q=='\0')
	 return m;
  }
  return NULL;
}
int main()
{
  char a[100],b[100];
  scanf("%s%s",a,b);
  puts(my_strstr(a,b));
  return 0;
}
