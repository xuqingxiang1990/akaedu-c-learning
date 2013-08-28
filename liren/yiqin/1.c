#include<stdio.h>

struct student
{
  char name[20];
  int id;
  char sex;
};

int main()
{
  struct student a[3];
  int i;
  char temp;
  for(i=0;i<3;i++)
    scanf("%s%d%c%c",a[i].name,&(a[i].id),&(a[i].sex),&temp);
  for(i=0;i<3;i++)
    printf("%s%d%c",a[i].name,a[i].id,a[i].sex);
  printf("\n");
  return 0;
}
