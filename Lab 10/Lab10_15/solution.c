#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int p12[2],p21[2];
	if(pipe(p12)<0 || pipe(p21)<0)
	{
		printf("Error creating pipe\n");
		exit(1);
	}

	FILE *fp;
	char ch;
	char filename[20];
	char lines[10];
	int line=0;
	
	pid_t pid;
	pid=fork();

	if(pid<0)
	{
		printf("Fork failed");
	}
	else if(pid>0)
	{
		close(p12[1]);
		read(p12[0],filename,20);

		close(p21[1]);
		read(p21[0],filename,10);
	}
	else
	{
		//proces client
		close(p12[1]);
		read(p12[0],filename,20);
		printf("proces client - dati fisier: ");
		scanf("%s",filename);

		//proces server
		close(p21[0]);
		write(p21[1],filename,20);
		fp=fopen(filename,"r");
		if(fp==NULL)
        	{
                	printf("File \"%s\" does not exist!\n",filename);
                	return -1;
        	}
	
        	while((ch=fgetc(fp))!=EOF)
        	{
                	if(ch=='\n')
                        	line++;
        	}

        	fclose(fp);
		printf("proces server - Total number of lines are %d\n",line);			
	}

}
