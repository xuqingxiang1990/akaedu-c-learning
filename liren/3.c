#include<stdio.h>
int is_email(char*str)
{
  char*p;
  int s=1;
  p=str;
  for(;*p!=0;p++)
  {
    switch(s)
	{
	 case 0:return 0;
	 case 1:
	       if((*p>='0'&&*p<='9')||(*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')||(*p='_'))
		     s=2;
		   else
		     s=0;
		   break;
	 case 2:
	       if(*p=='@')
		      s=3;
		   else if((*p>='0'&&*p<='9')||(*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')||(*p='_'))
		      s=2;
		   else 
		      s=0;
		   break;
	 case 3:
	       if(*p=='1')
		      s=4;
		   else
		      s=0;
		   break;
	 case 4:
	       if(*p=='6')
		      s=5;
		   else
		      s=0;
		   break; 
     case 5:
	       if(*p=='3')
		      s=6;
		   else
		      s=0;
		   break;
     case 6:
	       if(*p=='.')
		      s=7;
		   else
		      s=0;
		   break;
     case 7:
	       if(*p=='c')
		      s=8;
		   else
		      s=0;
		   break;
	 case 8:
	       if(*p=='o')
		      s=9;
		   else
		      s=0;
		   break;
	 case 9:
	       if(*p=='m')
		      s=10; 
		   else
		      s=0;
		   break;
	  case 10:
	         s=0;
		   break;
	}
  }
  if(s==10)
   return 1;
}
int main()
{
//  char*s="xuqingxiang@163.com";
  char s[100];
  scanf("%s",s);
  printf("%d\n",is_email(s));
  return 0;
}
