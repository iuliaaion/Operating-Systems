#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int p12[2],p13[2],p14[2];
	if(pipe(p12)<0 || pipe(p13)<0 || pipe(p14)<0)
	{
		printf("eroare la creerea pipeului");
		exit(1);
	} //creere pipe
	
	char string[30];
	printf("dati string:");	
	scanf("%[^\n]%*c",string);
	printf("%s",string);
	pid_t pid;
	
	if(pid<0)
	{
		printf("Forked failed");
	}
	else if(pid>0)
	{	
		//proces parinte
		close(p12[0]);
                write(p12[1],string,strlen(string)+1);
                close(p13[0]);
		write(p13[1],string,strlen(string)+1);
		close(p14[0]);
		write(p14[1],string,strlen(string)+1);

		wait(NULL);
	}
	else
	{
		//process 2
		char str[100];
		close(p12[1]);
		read(p12[0],str,100);
		int n=strlen(str);
		for(int i=0;i<n;i++) //verifica daca linia incepe cu litera
		{
			if(isalpha(str[0])!=0)
			{
				printf("\nProcesul 2, liniile care incep cu litera:%s\n",str);
			}
		}

		//process 3
		char string2[100];
		close(p13[1]);
		read(p13[0],string2,100);
		n=strlen(string2);
		for(int i=0;i<n;i++) //verifica daca linia incepe cu cifra
		{
			if(isdigit(string2[0])!=0)
			{
				printf("\nProcesul 3, liniile care incep cu cifre:%s\n",string2);
			}

		}

		//process 4
		char string3[100];
		close(p14[1]);
		read(p14[0],string3,100);
		n=strlen(string3);
		for(int i=0;i<n;i++) //printeaza restul liniilor
		{
			printf("\nProcesul 4: %s\n",string3);
		}
		exit(0);
	}
	return 0;
}
