#include<stdio.h>
struct STU
{
  char name[10];
  char sex;
  short i;
  char str[15];
  int id1;
  char b;
  int id;
};
int main()
{
  printf("%d\n",sizeof(struct STU));
  return 0;
}
