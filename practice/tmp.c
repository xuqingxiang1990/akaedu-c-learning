#include<stdio.h>
#include<math.h>
#define max 8
int sum=0;
int board[max];
void show_result()
{
  int i;
  sum=sum+1;
  printf("第%d种：",sum);
  for(i=0;i<max;i++)
  {
	printf("(%d,%d) ",i,board[i]);
  }
  printf("\n");
}
int check_cross(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
	if(board[i]==board[n]||(n-i)==abs(board[i]-board[n])) 
	return 1;
  }
  return 0;
}
void put_chess(int n)
{
  int i;
  for(i=0;i<max;i++)
  {
	board[n]=i;
	if(!check_cross(n))
	{
	  if(n==max-1)
		show_result();
	  else
		put_chess(n+1); 
	}
  }
}
void main()
{
  put_chess(0);

  return;
} 
