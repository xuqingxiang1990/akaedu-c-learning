nclude<stdio.h>
#include<stdlib.h>

int main()
{
  int x,y,p;
  int i,j;
  int qipan[12][12];
  int count;
  //初始化棋盘
  for(i=0; i<12; i++)
  {
	for(j=0; j<12; j++)
	{
	  qipan[i][j]=0;
	}
  }

  //下第一个子
  scanf("%d%d",&x,&y);
  //循环下子
  for(p=0;; p++)
  {
	system("cls");//刷新屏幕
	if(p%2==0&&qipan[x][y]==0)//棋子位置赋值,黑子为1,白子为2
	{
	  qipan[x][y]=1;
	}
	if(p%2==1&&qipan[x][y]==0)
	{
	  qipan[x][y]=2;
	}
	count=1;//开始判断游戏输赢
	for(i=x-1;i>0;i--)//竖向
	{
	  if(qipan[i][y]==qipan[x][y])
		count++;
	  if(qipan[i][y]!=qipan[x][y])//如果中间有空位或其他颜色棋子，则连珠失败，退出循环，下同
		break;
	}
	for(i=x+1;i<=11;i++)
	{
	  if(qipan[i][y]==qipan[x][y])
		count++;
	  if(qipan[i][y]!=qipan[x][y])
		break;
	}
	if(count<5)//横向
	{
	  count=1;
	  for(i=y-1;i>0;i--)
	  {
		if(qipan[x][i]==qipan[x][y])
		  count++;
		if(qipan[x][i]!=qipan[x][y])
		  break;
	  }
	  for(i=y+1;i<=11;i++)
	  {
		if(qipan[x][i]==qipan[x][y])
		  count++;
		if(qipan[x][i]!=qipan[x][y])
		  break;
	  }
	}
	if(count<5)//左上右下
	{
	  count=1;
	  for(i=x-1,j=y-1;i>0&&j>0;i--,j--)
	  {
		if(qipan[i][j]==qipan[x][y])
		  count++;
		if(qipan[i][j]!=qipan[x][y])
		  break;
	  }
	  for(i=x+1,j=y+1;i<=11&&j<=11;i++,j++)
	  {
		if(qipan[i][j]==qipan[x][y])
		  count++;
		if(qipan[i][j]!=qipan[x][y])
		  break;
	  }
	}
	if(count<5)//右上左下
	{
	  count=1;
	  for(i=x-1,j=y+1;i>0&&j>0;i--,j++)
	  {
		if(qipan[i][j]==qipan[x][y])
		  count++;
		if(qipan[i][j]!=qipan[x][y])
		  break;
	  }
	  for(i=x+1,j=y-1;i<=11&&j<=11;i++,j--)
	  {
		if(qipan[i][j]==qipan[x][y])
		  count++;
		if(qipan[i][j]!=qipan[x][y])
		  break;
	  }
	}

	printf("  1 2 3 4 5 6 7 8 9 10\n");//绘制棋子
	for(i=1; i<11; i++)
	{
	  if(i<10)
	  {
		printf(" %d",i);
	  }
	  else
	  {
		printf("%d",i);
	  }
	  for(j=1; j<11; j++)
	  {
		if(qipan[i][j]==0)
		{
		  printf("·");
		}
		if(qipan[i][j]==1)
		{
		  printf("●");
		}
		if(qipan[i][j]==2)
		{
		  printf("○");
		}
	  }
	  printf("\n");
	}
	if(count>=5)//判断输赢
	{
	  if(p%2==1)
	  {
		printf("白棋获胜！\n游戏结束！\n");
		break;
	  }
	  if(p%2==0)
	  {
		printf("黑棋获胜！\n游戏结束！\n");
		break;
	  }
	}
	printf("请输入坐标");//输入棋子坐标
	if(p%2==0)
	{
	  printf("(白子)：");
	}
	if(p%2==1)
	{
	  printf("(黑子)：");
	}
	for(;;)
	{
	  scanf("%d%d",&x,&y);
	  if((x<=10||y<=10)&&qipan[x][y]==0)
	  {
		break;
	  }
	  else
	  {
		printf("超出范围，或者此处已有棋子！\n请重新下子：");
	  }
	}
  }

  return 0;
}
