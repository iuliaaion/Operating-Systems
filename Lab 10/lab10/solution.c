#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	FILE *fp;
	char ch;
	char str1;
	char filename[20];
	int line_count=0;
	
	//declare the file
	printf("dati fisier:");
	scanf("%s",filename);

	//read from file	
	fp=fopen(filename,"r");
	printf("\nThe content of the file %s is:\n",filename);
	str1=fgetc(fp);
	while(str1 !=EOF)
	{	
		printf("%c",str1);
		str1=fgetc(fp);
	}	
	printf("\n\n");
	fclose(fp);

	
	
	return 0;
}
