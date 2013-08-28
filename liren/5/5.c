#include<stdio.h>
int main()
{
  char s[81]=" sj jsofo ofje  foe oj",c;
  int i,num=0,word=0;
//  scanf("%s",s);
  for(i=0;(c=s[i])!='\0';i++)
  {
    if(c==' ')
	 word=0;
	else if(word==0)
	{
	  word=1;
	  num++;
	}
  }
  printf("%d",num);
  return 0;
}
