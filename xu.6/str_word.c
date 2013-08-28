#include<stdio.h>
#include<string.h>

char* shift_word(char*s,char*str1,char*str2)
{
	char*p,*q,*m,*n;
	int i,j;
	char str[100];
	int len1,len2,len;
	n=str;
	len=strlen(s);
	len1=strlen(str1);
	len2=strlen(str2);
   	p=strstr(s,str1);            	// 位置 p-s;
	
	q=p;                           //q指向字串位置 

	for(j=0,i=p-s+len1;s[i]!='\0';i++)  //把要替换的单词后面的字符串存给n数组
	{
		n[j]=s[i];
		j++;
	}
	n[j]='\0';

	while(*str2!=0)                //str2拼接到str以前的
	{
		*q=*str2;
		q++;
		str2++;
	}

	while(*n!=0)                   //把n拼接到上面那个拼接的字符串
	{
		*q=*n;
		q++;
		n++;
	}
	*q='\0';

	return s;


	
}

char*my_scanf(char*s,int n)
{
	int len;
	fgets(s,n,stdin);
	len=strlen(s);
	s[len-1]='\0';
	return s;
	
}

int main(void)
{
	char s[100],str1[100],str2[100];
	int len;
	my_scanf(s,sizeof(s));
	my_scanf(str1,sizeof(str1));
	my_scanf(str2,sizeof(str2));
	printf("%s\n",shift_word(s,str1,str2));

	return 0;
}
