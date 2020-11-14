#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	char buff[100];
	fread(buff,sizeof(buff),1,fp);
	char string[50];
	int j=0;
	for(int i=0;i<strlen(buff);i=i+2)
	{
		string[j++]=buff[i];
	}
	fclose(fp);
	fp=fopen(argv[1],"w");
	fwrite(string,strlen(string),1,fp);
	fclose(fp);
	return 0;	
}
