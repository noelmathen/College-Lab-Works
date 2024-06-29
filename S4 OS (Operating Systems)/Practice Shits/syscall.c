#include<stdio.h>
#include<stdlib.h>
// #include<unistd.h>
#include<sys/types.h>
// #include<sys/wait.h>
#include<sys/stat.h>

void main(){
	struct stat file;
    stat("fork.c",&file);
    printf("file size: %ld",file.st_size);
}

