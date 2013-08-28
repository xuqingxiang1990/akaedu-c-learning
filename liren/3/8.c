#include<stdio.h>
#include<string.h>

void rev_print_str(char*s)
{
  char *p;
  int len;
  len=strlen(s);
  for(p=s+len-1;p>=s;p--)
    printf("%c ",*p);
  printf("\n");
}

void print_str(char*s)
{
  char *p;
  for(p=s;*p!='\0';p++)
    printf("%c ",*p);
  printf("\n");
}

char*my_strcat(char*s1,char*s2)
{
   char*p;
   p=s1;
   while(*p!='\0')
     p++;
   while(*s2!='\0')
   {
       *p=*s2;
	   p++;
	   s2++;
   }
   *p='\0';
   return s1;
}

char *my_strcpy(char *s1,char *s2)
{
  char *p;
  p=s1;
  while(*s2!='\0')
  {
    *p=*s2;
	p++;
	s2++;
  }
  *p='\0';
  return s1;
}
int main()
{
  char a[100],b[100];
  scanf("%s %s",a,b);
  print_str(a);
  rev_print_str(a);
  puts(my_strcat(a,b));
 puts(my_strcpy(a,b));
  return 0;
}
