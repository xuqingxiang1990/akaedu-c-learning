#include <stdio.h>
#include <string.h>

char *my_strstr(char *s1, char *s2)
{
	char *p, *p1, *p2;
	p = s1;
//	if(!*s2)
//		return s1;
	while(*p!='\0')
	{
		p1 = p;
		p2 = s2;
		while(*p1!=0 && *p2!=0 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if(*p2 == '\0')
			return p;
		p++;

	}
	return NULL;
}

int my_strcmp(char *s1, char *s2)
{
	int count1, count2;
	count1 = 0,count2 = 0;
	while(*s1!='\0')
	{
		count1++;
		s1++;
	}
	while(*s2!=0)
	{
		count2++;
		s2++;
	}
	if(count1 > count2)
		return 1;
	else if( count1 < count2)
		return -1;
	else if( count1 == count2)
		return 0;
}
int main(void)
{
	char s1[100], s2[100];
	int len;
	fgets(s1, sizeof(s1), stdin);
	len = strlen(s1);
	s1[len - 1] = '\0';

	fgets(s2, sizeof(s2), stdin);
	len = strlen(s2);
	s2[len - 1] = '\0';

	printf("%d\n", my_strcmp(s1, s2));
	
	printf("%s\n", my_strstr(s1, s2));

	return 0;

}
