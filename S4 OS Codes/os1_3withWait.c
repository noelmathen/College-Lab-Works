#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("\nChild PID: %d", getpid());
		printf("\nChild PPID: %d", getppid());
		exit(EXIT_SUCCESS);
	}
	else if(pid>0)
	{
		printf("\nParent PID: %d", getpid());
		printf("\nWaiting for child process to execute: \n");
		wait(NULL);
		printf("\nChild process was succesfully executed!\n");
	}
	else
	{
		printf("\nUnable to create child process\n");
	}
}

/*
n the provided code, a parent process is created using the `fork()` system call. The parent process calls `fork()`, which creates a new child process. The `fork()` system call returns different values to the parent and child processes.

Here's the explanation of the code:

1. The parent process executes the `fork()` system call, creating a new child process.
2. If the `fork()` call is successful and returns a non-negative value, the parent process receives the process ID (PID) of the child process in the `pid` variable.
3. If `pid` is 0, it means that the current process is the child process. In the child process, it prints its own process ID (`getpid()`) and its parent process ID (`getppid()`).
4. If `pid` is positive, it means that the current process is the parent process. In the parent process, it prints its own process ID (`getpid()`), indicates that it is waiting for the child process to execute, and waits for the child process to terminate using the `wait()` system call.
5. Once the child process terminates, the parent process resumes execution and prints a message indicating that the child process was successfully executed.
6. If `fork()` fails and returns a negative value, it means that the creation of the child process was unsuccessful, and an appropriate error message is printed.

The `wait()` system call in the parent process ensures that the parent process waits for the child process to finish executing before proceeding. This allows the parent process to synchronize its execution with the child process.
*/

