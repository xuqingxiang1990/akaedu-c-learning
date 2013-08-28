#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *concat( char*s1,char*s2)
{
  char *result;
  result=malloc(strlen(s1)+strlen(s2)+1);
  if(result==NULL)
  {
    printf("Error");
	//exit(EXIT_FAILURE);
  }
  strcpy(result,s1);
  strcat(result,s2);
  return result;
}
int main()
{
  printf("%s\n",concat("abcd","edfg"));
  return 0;
}
