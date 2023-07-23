#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
	fork();
	fork();
	fork();
	printf("\nHello World\n");
}

/*
Sure! Let's go through the code step by step:

1. `fork()`: The `fork()` system call is used to create a new process by duplicating the existing process. After the `fork()` call, two identical processes are created, and both continue executing from the next line of code.

2. The first `fork()` call creates a child process. Both the parent and child processes continue executing the code from the next line.

3. The second `fork()` call creates two more child processes. Now, there are a total of four processes running concurrently, including the parent process.

4. The third `fork()` call creates four additional child processes. Now, there are a total of eight processes running concurrently, including the parent process.

5. Each of the eight processes continues execution from the next line of code, which is `printf("\nHello World\n");`.

6. Since all the processes execute the `printf()` statement, the string "Hello World" will be printed eight times. Each process has its own output stream, so the output may appear interleaved or in a different order depending on the operating system's process scheduling.

To summarize, the code demonstrates the creation of multiple child processes using the `fork()` system call, resulting in a total of eight processes (including the parent process) printing "Hello World" as output.
*/