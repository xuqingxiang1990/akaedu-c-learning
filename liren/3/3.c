#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* hebing(char*s1,char*s2)
{
  char*p;
  p=malloc(strlen(s1)+strlen(s2)+1);
  if(p==NULL)
  {
    printf("Eorror");
	exit(EXIT_FAILURE);
  }
  strcpy(p,s1);
  strcat(p,s2);
  return p;
}
int main()
{
  char s1[100],s2[100];
  scanf("%s %s",s1,s2);
  printf("%s\n",hebing(s1,s2));
  return 0;
}
