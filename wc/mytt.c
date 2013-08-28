#include <stdio.h>

int main(void)
{                                               //单词个数  行数 字符数
  char str[128];
  int s1, s2, s3;
  s1 = s2 = s3 = 0;
  while(1)
  {

	int i = 0;
	char *p, ch;
	p = fgets(str, 128, stdin);
	if(p == NULL)
	  break;
	while((ch = str[i++])!='\0')
	{
	  int count = 0;
	  char word[32];
	  if(!isalpha(ch))
		continue;
	  do
	  {
		word[count++] = ch;
		ch = str[i++];
		s2++;
	  }while(isalpha(ch));
	  word[count] = '\0';
	  s1++;
	}
  }
  printf("%d\n", s1);
  return 0;
}
