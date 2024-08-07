#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(){
    int welcomeSocket, newSocket;
    char buf[1024];
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_in serverStorage;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    if(listen(welcomeSocket, 5) == 0){
        printf("\nListening");
    }
    else{
        printf("\nError");
    }

    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    while(1){
        recv(newSocket, buffer, 1024, 0);
        printf("\nReply > %s", buffer);
        printf("\nEnter message: ");
        fgets(buf, 1024, stdin);
        printf("\nMessage sent");
        strcpy(buffer, buf);
        send(newSocket, buffer, sizeof(buffer), 0);
    }
    return 0;
}