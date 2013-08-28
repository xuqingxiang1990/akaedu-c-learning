#include<stdio.h>
int wordcount(char p[])
{
int i=0,count=0;
if(p[0]==' ')
i++;
for(i=1;p[i]!='\0';i++)
{
  if(p[i]==' '&&p[i-1]!=' ')
   count++;
}
return count+1;
}
int main()
{
  int word,i,num=0;
  char str[100],c;
  scanf("%s",str);
  word=wordcount(str);
  printf("%d\n",word);
  return 0;
  }

