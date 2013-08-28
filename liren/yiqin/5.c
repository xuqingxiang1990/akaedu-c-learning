#include<stdio.h>
#include<string.h>

struct teacher
{
  char name[10];
  int age;
  int id;
  char sex;
};

void maopao(struct teacher*s,int n)
{
  int i,j;
  struct teacher temp;
  for(i=1;i<n;i++)
    for(j=0;j<n-i;j++)
    {
      if(s[j].age>s[j+1].age)
      {
	temp=s[j];
	s[j]=s[j+1];
	s[j+1]=temp;
      }
    }
}

char*mystr(char *str,int len1)
{
    int len;
    fgets(str,len1,stdin);
    len=strlen(str);
    str[len-1]='\0';
    return str;
}

int main()
{
  struct teacher a[3];
  char str[100];
  int i,len;
 /* for(i=0;i<3;i++)
  {
    mystr(str,sizeof(str));
    strcpy(a[i].name,str);

    mystr(str,sizeof(str));
    a[i].age=atoi(str);

    mystr(str,sizeof(str));
    a[i].id=atoi(str);

    mystr(str,sizeof(str));
    a[i].sex=str[0];
  }*/
  for(i=0;i<3;i++)
  {
    scanf("%s",a[i].name);
    getchar();
    scanf("%d",&(a[i].age));
    getchar();
    scanf("%d",&(a[i].id));
    getchar();
    scanf("%c",&(a[i].sex));

  }
  maopao(a,3);
  for(i=0;i<3;i++)
    printf("%s\t%d\t%d\t%c \n",a[i].name,a[i].age,a[i].id,a[i].sex);
  return 0;
}
