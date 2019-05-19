//Amrit Poudel 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	int y;

	if (argc!=2)
	{
		printf("Usage: %s <starting Value>\n", argv[0]);
		return;
	}
	y = atoi(argv[1]);	
	if (y<=0)
	{
		printf("<starting Value> Enter a popsitive integer\n");
		return;
	} 
	pid_t pid;
	pid = fork();

	if (pid<0)
	{ 
		fprintf(stderr, "Fork has Failed");
		return 1;
	}
	else if (pid == 0)
	{ 
		printf("%d",y);
		
		while (y!=1)
		{
			if(y%2 == 0)
			{
				y=y/2;
			}
			else if(y%2 == 1)
			{
				y = (3 * y) + 1;
			}
			printf(", %d",y);
		}
		printf("\n");
			
	}
	else
	{
		wait(NULL);
	}
	return 0;
}





