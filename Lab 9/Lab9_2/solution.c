#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	printf("Give number:");
	int n;
	scanf("%d",&n);
	for(int i=4;i<n;i++)
	{
		if(fork()==0)
		{
			int sum=1;
			for(int j=2;j<=i/2;j++)
			{
				if(i%j==0)
					sum+=j;
			}
			if(i==sum)
				printf("\n It's perfect number:%d\n",i);
			exit(0);
		}
	}
	for(int i=4;i<n;i++)
		wait(NULL);

	return 0;
}
