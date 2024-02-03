#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("******PIPES******\n");
	int fd[2];
	char buffer[100], text[100];
	pipe(fd);
	pid_t p=fork();
	if(p>0)
	{
		printf("\nParent pass value to child");
		printf("\nEnter data: ");
		fgets(text, 100, stdin);
		write(fd[1], text, 100);
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
