#include<stdio.h>
void print_str2(char*s)
{
  char *p,*q;
  p=s;
  while(*p!='/')
   p++;
  *p='\0';
  printf("%s",p);

    
  /*for(p=s;*p!='\0';p++)
  {
     q=p;
	 while(*p!='/')
	 {
	   *q=*p;
	   p++;
	   q++;
	 }
	 *q='\0';
  }
  for(;*q!='\0';q++)
    putchar(*q);*/
 
}

int main()
{
  char*s="nihaoxu/*许庆祥*/qingxiang";
  print_str2(s);
  return 0;
}
