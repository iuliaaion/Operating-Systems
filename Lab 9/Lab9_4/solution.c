#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int main()
{
	pid_t fork();
	printf("Give number:");
	int n;
	scanf("%d",&n);
	int i=2,p; // initializam i cu 2 deoarece este primul divizor posibil, iar p reprezinta ordinul de multiplicitate
	if(fork()==0)
	{
		while(n>1)
                {
                        p=0;
                        while(n%i==0)
                        {
                                p++;
                                n=n/i;
                        }
                        if(p>0)
				printf("\nDecomposition %d ^ %d\n",i,p);
                        i=i+1;
                 }
		exit(0);
	}
	else
	{	
		while(n>1)
		{	
			if(n%i==0)
                       		printf("%d it's a divisor for %d ",i,n);	
			p=0;
                        while(n%i==0)
                        {
                                p++;
                                n=n/i;
                        }
                        if(p>0)
				printf("- order of mulitplicity: %d\n",p);
                        i=i+1;
                }
	wait(NULL);
	}

	return 0;
}
