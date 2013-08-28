#include<stdio.h>
#include<time.h>
void  print_chess(int a[][10])    //打印棋盘  初始化
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			a[i][j]=0;

	printf("   ");
	for(i=0;i<10;i++)
   		printf("%2d",i);	
	putchar(10);
	printf("   ");
	for(i=0;i<10;i++)
		printf(" _");
	putchar(10);

	for(i=0;i<10;i++)
	{
		printf("%2d|",i);
		for(j=0;j<10;j++)
		{
			printf("%2d",a[i][j]);
		}
		putchar(10);
	}
}


int foo(int x,int y,int z,int a[][10])      //玩家1和玩家2下棋（更新棋盘）
{
		int i,j;
		a[x][y]=z;
		printf("   ");
		for(i=0;i<10;i++)
   		printf("%2d",i);	
		putchar(10);

		printf("   ");
		for(i=0;i<10;i++)
		printf(" _");
		putchar(10);
		
		for(i=0;i<10;i++)
		{
			printf("%2d|",i);
			for(j=0;j<10;j++)
			{
				printf("%2d",a[i][j]);				
			}
			putchar(10);
		}

}

int my_scanf(int p,int *a,int *b,int c[][10])      //判断是否溢出棋盘和重复棋子
{
	while(1)
	{
		printf("player%d\n",p);
		scanf("%d%d",a,b);
		if(*a>10||*b>10||c[*a][*b]!=0)
			{
				printf("%d %d is not permitted! pleare reininput\n",*a,*b);
				continue;
			}
		else
			break;
	}
}

int decide(int a[][10], int *pa, int *pb, int person)//判断玩家赢棋；
{
  int i, j, cont = 0;
  for(i=*pa; i<10; i++) {              //横行
	if(a[i][*pb]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(i=*pa; i>=0; i--) {   
	if(a[i][*pb]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(j=*pb; j>=0; j--) {             //竖行
	if(a[*pa][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(j=*pb; j<10; j++) {   
	if(a[*pa][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }

  
  cont=0;
  for(j=*pb, i=*pa; i<10&&j<10; i++, j++) {          
	if(a[i][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(j=*pb, i=*pa; i>=0&&j>=0; i--, j--) {   
	if(a[i][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(j=*pb, i=*pa; i>=0&&j<10; i--, j++) {   
	if(a[i][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  cont=0;
  for(j=*pb, i=*pa; i<10&&j>=0; i++, j--) {   
	if(a[i][j]==person)
	  cont++;
	else
	  break;
	if(cont==5)
	  return cont;
  }
  return 0;

}


void judge(int *a, int *b, int *m, int *n, int c[][10])
{
	int i,j;
	int w,q,count=0;
	for(i=*a;i>0;i--) {
		if(c[i][*b]==1)
			count++;
			w=count;
	}
	for(i=*a;i<10;i++)
		if(c[i][*b]==1)
			count++;
	if(count==3)
		*n=*a-w;
	*m=*a;
}

int main()
{
	int a,b,c[10][10];
	int m,n;
	int count1,count2;
	printf("start game\n");
	print_chess(c);                        //初始化棋盘
	srand(time(NULL));
	while(1)
	{
		my_scanf(1,&a,&b,c);               //玩家一下棋（横竖坐标代表棋子）
		foo(a,b,1,c);
		count1=decide(c,&a,&b,1);          //判断是否赢棋
		if(count1==5)
		{
			printf("you are clever");
			break;
		}

		my_scanf(2,&a,&b,c);                //玩家二下棋
	//	judge(&a,&b,&m,&n,c);
		foo(a,b,2,c);
		count2=decide(c,&a,&b,2);            //判断是否赢棋
		if(count2==5)
		{
			printf("you are clever");
			break;
		}
	}
	putchar(10);
	return 0;
}
