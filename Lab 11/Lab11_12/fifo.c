#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){

	char dir[100];
	pid_t pid;
	printf("Give director name: ");
	scanf("%s",dir);
	if(mkfifo("list",0666) == -1)
	{
		fprintf(stdout,"File already exist\n");
	}
	int fd=open("list",O_RDWR);
	pid=fork();
	if(pid<0)
	{
		printf("Fork failed");
		return 1;
	}	
	else
		if(pid>0)
		{
			char fisiere[100];
			write(fd,dir,strlen(dir)+1);
			wait(NULL);
			read(fd,fisiere,100);
			if(strcmp(fisiere,"")>0)
				printf("List of text files:\n%s",fisiere);
			else
				printf("This director doesn't exist\n");
		}
		else
		{
			char fisiere[100]= "", dir2[100], buff[120], com[50]="ls ";
			read(fd,dir2,100);
			strcat(com,dir2);
			strcat(com,"| grep .txt");
			FILE *fp;
			fp=popen(com,"r");
			while(fgets(buff,sizeof(buff),fp) != NULL)
				strcat(fisiere,buff);
			pclose(fp);
			write(fd,fisiere,strlen(fisiere)+1);
			exit(0);
		}

	close(fd);
	unlink("list");
	return 0;

}
