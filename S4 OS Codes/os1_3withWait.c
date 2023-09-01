#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void child()
{
	printf("\nChild process gets executed\n");
}

void parent()
{
	printf("\nParent process gets executed\n");
}

int main()
{
	pid_t pid = fork();
	
	if(pid == 0)
	{
		child();
		exit(EXIT_SUCCESS);
	}
	else if(pid>0)
		parent();
	else
		printf("\nUnable to create child process\n");
}

/*
Certainly! Let's break down the code step by step:

1. First, the necessary header files (`stdio.h`, `stdlib.h`, `unistd.h`, `sys/types.h`) are included.

2. The `child()` function is defined. This function will be executed by the child process.

3. The `parent()` function is defined. This function will be executed by the parent process.

4. In the `main()` function, a variable `pid` of type `pid_t` is declared. `pid_t` is a data type used to represent process IDs.

5. The `fork()` system call is used to create a new process. It returns the process ID (`pid`).

6. If `pid` is 0, it means the current process is the child process. Inside the `if` block, the `child()` function is called, and `exit(EXIT_SUCCESS)` is used to terminate the child process. `EXIT_SUCCESS` is a constant representing a successful exit status.

7. If `pid` is greater than 0, it means the current process is the parent process. Inside the `else if` block, the `parent()` function is called.

8. If `fork()` returns a negative value, it means an error occurred and the child process could not be created. In this case, an error message is printed inside the `else` block.

9. The program execution completes, and the parent and child processes terminate.
To summarize, the code demonstrates the creation of a child process using the `fork()` system call. The child process executes the `child()` function, while the parent process executes the `parent()` function.
In the code provided, the order in which the parent and child processes execute is not deterministic. The order of execution depends on the scheduling algorithm of the operating system.


Here's what could happen:
1. The parent process executes the `fork()` system call, creating a new child process.
2. Both the parent and child processes continue execution from the point after the `fork()` call.
3. Depending on the scheduling algorithm, the operating system may give priority to either the parent or the child process.
4. If the parent process gets scheduled first, it executes the `parent()` function and prints "Parent process gets executed" before the child process gets scheduled.
5. If the child process gets scheduled first, it executes the `child()` function and prints "Child process gets executed" before the parent process gets scheduled.
The order of execution is not fixed and can vary each time the program runs.
*/
