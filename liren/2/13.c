#include<stdio.h>
int main()
{
  int word=0,i,num=0;
  char str[100],c;
  scanf("%s",str);
  for(i=0;(c=str[i])!='\0';i++)
   {
     if(c==' ')
	   word=0;
	 else if(word==0)
	 {
	   word=1;
	   num++;
	   }
   }
   printf("%d\n",num);
   return 0;
}
