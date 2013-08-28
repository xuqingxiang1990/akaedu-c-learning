#include <stdio.h>
#include <stdlib.h>

struct number_guess
{
  int num[3];
};

struct guessnumber
{
  int nCount;
  number_guess guess[128];
};

void savelog(char *pBuffer )
{
  FILE * fp = fopen("guess.log", "a+");
  if (!fp )
	return ;


  fwrite(pBuffer,1,strlen(pBuffer),fp);
  fclose(fp);
}
guessnumber g_guessnumber[32]={0};
void calcnumber(int curnumber)
{
  g_guessnumber[curnumber].nCount = g_guessnumber[curnumber-1].nCount+g_guessnumber[curnumber-2].nCount;
  number_guess *pGuess =  g_guessnumber[curnumber].guess;


  for (int i =0;i< g_guessnumber[curnumber-2].nCount;i++)
  {
	memcpy(&pGuess->num,&g_guessnumber[curnumber-2].guess[i].num,3*sizeof(int));
	if (0==curnumber%3)
	  pGuess->num[0] = pGuess->num[1]+pGuess->num[2];
	else if (1==curnumber%3)
	  pGuess->num[1] = pGuess->num[0]+pGuess->num[2];
	else if (2==curnumber%3)
	  pGuess->num[2] = pGuess->num[0]+pGuess->num[1];
	pGuess++;
  }


  for (int i =0;i< g_guessnumber[curnumber-1].nCount;i++)
  {
	memcpy(&pGuess->num,&g_guessnumber[curnumber-1].guess[i].num,3*sizeof(int));
	if (0==curnumber%3)
	  pGuess->num[0] = pGuess->num[1]+pGuess->num[2];
	else if (1==curnumber%3)
	  pGuess->num[1] = pGuess->num[0]+pGuess->num[2];
	else if (2==curnumber%3)
	  pGuess->num[2] = pGuess->num[0]+pGuess->num[1];
	pGuess++;
  }




}




int main()

{
  g_guessnumber[0].nCount =1;
  g_guessnumber[0].guess[0].num[0]=2;
  g_guessnumber[0].guess[0].num[1]=1;
  g_guessnumber[0].guess[0].num[2]=1;


  g_guessnumber[1].nCount =2;
  g_guessnumber[1].guess[0].num[0]=1;
  g_guessnumber[1].guess[0].num[1]=2;
  g_guessnumber[1].guess[0].num[2]=1;


  g_guessnumber[1].guess[1].num[0]=2;
  g_guessnumber[1].guess[1].num[1]=3;
  g_guessnumber[1].guess[1].num[2]=1;


  g_guessnumber[2].nCount =4;


  g_guessnumber[2].guess[0].num[0]=1;
  g_guessnumber[2].guess[0].num[1]=1;
  g_guessnumber[2].guess[0].num[2]=2;


  g_guessnumber[2].guess[1].num[0]=2;
  g_guessnumber[2].guess[1].num[1]=1;
  g_guessnumber[2].guess[1].num[2]=3;


  g_guessnumber[2].guess[2].num[0]=1;
  g_guessnumber[2].guess[2].num[1]=2;
  g_guessnumber[2].guess[2].num[2]=3;


  g_guessnumber[2].guess[3].num[0]=2;
  g_guessnumber[2].guess[3].num[1]=3;
  g_guessnumber[2].guess[3].num[2]=5;


  char szBuffer[10240]="";


  for (int i =3;i <8;i++)
  {
	calcnumber(i);
	sprintf(szBuffer ,"%s num=%d,number=%d,",szBuffer ,i+1,g_guessnumber[i].nCount);
	for (int j =0;j<g_guessnumber[i].nCount;j++)
	{
	  number_guess *pGuess =  g_guessnumber[i].guess+j;


	  for (int k=0;k<3;k++)
	  {
		sprintf(szBuffer,"%s%d:",szBuffer ,pGuess->num[k]);


	  }
	  strcat(szBuffer,",");
	}
	strcat(szBuffer,"\n");
  }
  printf(szBuffer);
  savelog(szBuffer);
  getchar();
  return 0;
}
