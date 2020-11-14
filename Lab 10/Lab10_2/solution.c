#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int p12[2],p13[2],p14[2],p25[2],p35[2];
	if(pipe(p12)<0 || pipe(p13)<0 || pipe(p14)<0 || pipe(p25)<0 || pipe(p35)<0)
	{
		printf("Error creating pipe");
		exit(1);
	} 

	char string[10];
	char string2[10];
	char str[10];

	printf("Give string:");
	scanf("%s",string);
	pid_t pid;
	pid=fork();

	if(pid<0)
	{
		printf("Forked failed");
	}
	else if(pid>0)
	{
		//proces parinte
		close(p14[0]);
		write(p14[1],string,strlen(string)+1);
		close(p12[0]);
		write(p12[1],string,strlen(string)+1);
		close(p13[0]);
		write(p13[1],string,strlen(string)+1); 
		
		wait(NULL); 
		
		close(p35[1]);
		read(p35[0],string,10);
		printf("\nObtained string:%s\n",string);

		close(p25[1]);
		read(p25[0],str,10);
		printf("\nSum is:%s\n",str);
	} 
	else
	{
		//process4
		char str[10];
		close(p14[1]);
		read(p14[0],str,10); 
		int n=strlen(str);
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if(str[i]>str[j])
				{
					char temp=str[i];
					str[i]=str[j];
					str[j]=temp;
				}
		printf("\nProcesul 4: %s\n",str);
		
		//process2
		close(p12[1]);
		read(p12[0],string2,10);
		n=strlen(string2);
		int suma=0;
		for(int i=0;i<n;i++) 
		{
			if(isdigit(string2[i])!=0)
			{
				int x=string2[i]-'0';
				suma+=x;
			}
			if(isalpha(string2[i])!=0)
			{
				string2[i]='z';
			}
		}
		
		close(p35[0]);
		write(p35[1],string2,strlen(string2)+1);
		char sumanumar[10];
		sprintf(sumanumar,"%d",suma);
		close(p25[0]);
		write(p25[1],sumanumar,strlen(sumanumar)+1);
		
		exit(0);

	}

	return(0);

}
