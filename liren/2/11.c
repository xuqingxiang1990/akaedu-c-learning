#include<stdio.h>
#include<string.h>
char *print_str(char*s1)
{
 char *p,*q,*m;
 int len,len1;
 len=strlen(s1);
 p=s1;
 while(*p!='/'&&*(p+1)!='*')
   p++;
 q=s1+len-1;
 while(*q!='/')
 {
   *p=*q;
   q--;
   p++;
 }
 *p='\0';
 return p;
}

int main()
{
  char s1[100]="xuqing/*你好*/nihao",s2[100];
 // scanf("%s",s1);
  //scanf("%s",s2);
  printf("%s ",print_str(s1));
  printf("\n");
  return 0;
}
