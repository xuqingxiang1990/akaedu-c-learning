#include<stdio.h>
int mystrlen(char *str)
{
  int i,count=0;
  char *p;
  for(p=str;p!='\0';p++)
    count++;
  return count;
}
int main()
{
   char buf[128]="sjlfjoej";
   char *s="kjoeijohjgosogj";
   printf("buf=%d,s=%d\n",mystrlen(buf),mystrlen(s));
   return 0;

}
