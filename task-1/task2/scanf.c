#include <stdio.h>

int main(void)
{
  FILE *fp;
  char ch;
  char str[1024];
  fp = fopen("b.txt", "a+");
  char name[32];
       char cname[16];
       int age;
       char gender[4];
       char native[16];
       char tel[16];
       char qq[16];
       char email[1208];
       char hobby[1208];
       int n;
	   char ww[10];
	//   scanf("%d", &age);
	 //  printf("%d\n", age);
	   #if 1
       scanf("%s%s%d%s%s%s%s%s%s", name, cname,&age, gender, native, tel, qq, email, hobby);
		fprintf(fp,"%s  %s  %d  %s  %s  %s  %s  %s  %s\n",name, cname, age, gender, native, tel, qq, email, hobby);
		#endif
		rewind(fp);
		fgets(str, sizeof(str), fp);
			fputs(str, stdout);
//		fprintf(
//		while((ch = fgetc(fp)) != EOF)
//			fputc(ch, stdout);
       
	     fclose(fp);
	return 0;

}
