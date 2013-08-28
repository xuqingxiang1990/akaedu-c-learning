#include<stdio.h>
int chazhao(char a[], char s)
{
  int i=0;
  while(a[i]!='\0')
  {
   if(a[i]==s)
      return i;
	  i++;
  }
  return -1;
}
int main()
{
   int i;
   char a[10],s;
  // char a[]="xuqingxiang",s;
  for(i=0;a[i]!='\n';i++)
     scanf("%s",a[i]);
   scanf("%c",&s);
   printf("%d\n",chazhao(a,s)+1);
   return 0;
}
