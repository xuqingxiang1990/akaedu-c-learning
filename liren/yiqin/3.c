#include<stdio.h>
#include<string.h>

struct student{
  char name[10];
  int id;
  char sex;
};

int main()
{
  char str[100];
  int i,len;
  struct student a[3];
  for(i=0;i<3;i++)
  {
    fgets(str,sizeof(str),stdin);
    len=strlen(str);
    str[len-1]='\0';
    strcpy(a[i].name,str);

    fgets(str,sizeof(str),stdin);
    len=strlen(str);
    str[len-1]='\0';
    a[i].id=atoi(str);

    fgets(str,sizeof(str),stdin);
    len=strlen(str);
    a[i].sex=str[0];

  }

for(i=0;i<3;i++)
  printf("%s %d %c\n",a[i].name,a[i].id,a[i].sex);
  return 0;
}
