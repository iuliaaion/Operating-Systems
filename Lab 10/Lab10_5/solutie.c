#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int p12[2],p13[2],p14[2];
	if(pipe(p12)<0 || pipe(p13)<0 || pipe(p14)<0)
	{	
		printf("eroare la creerea pipeului");
		exit(1);
	} //creere pipe

	char string[30];
	
	printf("Give string:");
	fgets(string,30,stdin);
}
