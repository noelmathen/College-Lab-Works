#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    int fd[2];
    char buffer[100], mes[100];
    pipe(fd);
    pid_t p = fork();
    if(p>0){
        printf("Parent to child");
        printf("Enter data");
        fgets(mes, 100, stdin);
        write(fd[1], mes, 100);
        wait(NULL);
    }
    else{
        read(buffer, mes, 100);
        printf("Data received: %s", buffer);
    }
}