#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("******PIPES******\n");
	int fd[2], n;
	char buffer[100], as[100];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0)
	{
		printf("\nParent pass value to child");
		printf("\nEnter data: ");
		fgets(as, 100, stdin);
		write(fd[1], as, 100);
		wait(NULL);
	}
	else
	{
		read(fd[0], buffer, 100);
		printf("\nChild received data");
		printf("\nBuffer: %s", buffer);
		return 0;
	}
}
