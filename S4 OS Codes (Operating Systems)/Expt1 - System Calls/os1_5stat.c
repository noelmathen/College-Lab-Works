#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void main()
{
	struct stat file;
	stat("os1_3withWait.c", &file);
	printf("\nSize of file = %ld bytes\n", file.st_size);
}

/*
this code demonstrates the usage of the `stat()` function from the `sys/stat.h` header file. This function is used to retrieve information about a file, such as its size, permissions, timestamps, and more.

Here's an explanation of the code:

1. `struct stat file;`: This line declares a structure `file` of type `struct stat` which is used to store the file information returned by the `stat()` function.

2. `stat("os3withWait.c", &file);`: This line calls the `stat()` function to obtain information about the file named "os3withWait.c". The first argument is the name of the file, and the second argument is the address of the `struct stat` variable where the file information will be stored. The `stat()` function retrieves the file information and fills the `file` structure with the details.

3. `printf("\nSize of file = %ld\n", file.st_size);`: This line prints the size of the file by accessing the `st_size` member of the `struct stat` variable `file`. The `%ld` format specifier is used to print a `long int` value, which is the data type of `st_size`. This will display the size of the file in bytes.

The code fetches the size of the file "os3withWait.c" using the `stat()` function and displays it using `printf()`. It can be used to determine the size of a file in bytes, which can be useful for various file-related operations or informational purposes.
*/

