#include <stdio.h>
#include <string.h>

struct word {
  char name[32];
  int len;
  int freq;
  int wc;
  char trans[64];
};

typedef struct word word_t;

#define N 16000

word_t words[N], word1[N];


void get_translation(char * word, char * trans)
{
  char cmd[64];
  char buf[10240];
  char * tmpfile = "t.tmp";
  FILE * fp;
  char * p;

  strcpy(cmd, "");
  strcat(cmd, "./trans.rb ");
  strcat(cmd, word);
  strcat(cmd, " > ");
  strcat(cmd, tmpfile);

  system(cmd);

  fp = fopen(tmpfile, "r");
  fscanf(fp, "%s", buf); 
  fclose(fp);

  p = strtok(buf, "\"");

  p = strtok(NULL, "\"");

  strcpy(trans, p);
  return;
}



/******************************冒泡排序********************************/

void sort( int n)
{
  int i, j;
  word_t temp;
  for(i = 1; i < n; i++)
	for(j = 0; j < n - i; j++)
	  if(word1[j].freq < word1[j+1].freq)
	  {
		temp = word1[j + 1];
		word1[j + 1] = word1[j];
		word1[j] = temp;
	  }
}


int main(void)
{
  char ch, word_max[32];
  int flag = 0, k = 0, m = 0, max = 0, i = 0;
  int counter ;
  int j;
  /***************************找出单词并储存**********************************/

  while((ch = getchar())!=EOF)
  {
	char word[32];
	if(isalpha(ch))
	{
	  word[i++] = ch;
	  flag = 1;
	  m++;
	}

	if(!isalpha(ch) && flag == 1)
	{
	  word[i] = '\0';
	  i = 0;
	  strcpy(words[k].name, word);   //复制给结构体
	  word1[k].wc = k + 1;
	  k++;
	  m = 0;
	  flag = 0;
	}

  }
  /********************找出最长的单词**************************************/

  for(i = 0; i < k ; i++)               //对结构体操作            
  {
	words[i].len = strlen(words[i].name);
	printf("len = <%d>  word = <%s>\n", words[i].len, words[i].name);
	if(words[i].len > max)
	{
	  max = words[i].len;
	  strcpy(word_max, words[i].name);
	}	
  }

  for(i = 0; i < k ; i++)            //最长单词并打印
	if(words[i].len == max)
	  printf("maxlen = %d maxword = <%s>\n", words[i].len,words[i].name);

  /***********找出重复的单词并统计重复单词的个数打印*****************/

  int flag1[16000];      
  int w = 0;
  for(i = 0; i < k; i++)             //初始化标志位
	flag1[i] = 1;

  for(i = 0; i < k; i++)              //找到相同的单词并统计个数
  {
	if(flag1[i] == 1)
	{
	  counter = 1;
	  for(j = i + 1; j < k; j++)
	  {

		if((strcmp(words[i].name, words[j].name)== 0))
		{
		  counter++;
		  flag1[j] = 0;
		}
	  }
	  strcpy(word1[w].name, words[i].name);   //赋給结构体word1;
	  words[i].freq = counter;
	  word1[w].freq = counter;
	  char trans[64] = "trans";                     //翻译
	  get_translation(word1[w].name,trans);
	  strcpy(word1[w].trans, trans);
	  w++;
	}

  }

  /****************************排序打印****************************************/
  sort( k);
  for(i = 0; i < w; i++)
  {
	strcat(word1[i].name, ">");
	printf("wc = <%-4d>  word = <%-18s freq = %d, trans = (%s)\n", word1[i].wc,\
		word1[i].name, word1[i].freq, word1[i].trans);
  }

  return 0;

}




