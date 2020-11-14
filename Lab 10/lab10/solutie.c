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
        int line=0;

        //declare the file
        printf("dati fisier:");
        scanf("%s",filename);

        //open file in read mode
        fp=fopen(filename,"r");
        
	if(fp==NULL)
	{
		printf("File \"%s\" does not exist!\n",filename);
		return -1;	
	}
	
	//read character by character and check for new line
	while((ch=fgetc(fp))!=EOF)
	{	
		if(ch=='\n')
			line++;
	}
	
	//close file
	fclose(fp);
	
	printf("Total number of lines are %d\n",line);



        return 0;
}

