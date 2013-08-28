stu_t file(char *argv, stu_t stu)
{
	FILE *fp;
    char str[1024];
    int num = 0;
	char *p;
    fp = fopen(argv, "r");
    if(fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    while(fgets(str, sizeof(str), fp) != NULL)
    {
        strcpy(stu[num].name, strtok(str, " "));
        while(p = strtok(NULL, " ") != NULL)
        {
           strcpy(stu[num].cname, p);
		   fputs(stu[num].cnme, stdout);
        }
        num++;
    }
    fclose(fp);

//	return stu;
}
