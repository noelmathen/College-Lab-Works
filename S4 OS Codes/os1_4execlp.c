#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	//output of first file is input of second file
	execlp("./hi", "os1_2withoutWait", NULL);
}

/*
The execlp() function is a C library function that is used to replace the current process with a new process. It belongs to the unistd.h header file and is part of the POSIX (Portable Operating System Interface) standard.The function allows you to execute a specified program by providing its path and arguments. 
The provided code demonstrates the usage of the `execlp()` function in the context of process execution.

Here's the explanation of the code:

1. The `execlp()` function is called with three arguments:
   - The first argument is the path to the executable file to be executed (`"./hi"` in this case). This assumes that there is a file named "hi" in the current directory.
   - The second argument is the name to be assigned to the executed program as its first argument (`"os2withoutWait"` in this case).
   - The third argument is set to `NULL`, indicating the end of the argument list.

2. When `execlp()` is called, the current process (the parent process) is replaced by the execution of the specified program ("hi" in this case).

3. The executed program ("hi") takes the place of the current process, inheriting its PID (Process ID) and other attributes.

4. The purpose of the `execlp()` function in this code is to execute the program "hi" with the specified name and no additional arguments. It essentially replaces the current process with the execution of the specified program.

5. Once the `execlp()` function is called, the execution of the current program (the parent process) is terminated, and the control is transferred to the executed program ("hi").

Note: It is important to ensure that the specified executable file ("hi" in this case) is present in the current directory and has appropriate permissions to execute.
*/


//In this code for executing, refer the output image.
//Before executing this file, execute any other file(here, "os2withoutWait.c") in the following way:
//	"" gcc -o hi os1_2withoutWait.c ""
//	"" ./hi  ""
//do this and then execute this file
