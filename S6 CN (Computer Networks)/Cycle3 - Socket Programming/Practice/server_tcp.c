#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024], buf[1024];
    struct sockaddr_in serverAddr, serverStorage;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(welcomeSocket, (struct sock_addr *) &serverAddr, sizeof(serverAddr));

    if(listen(welcomeSocket, 5)==0)
        printf("\nListening");
    else
        printf("\nError");

    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    while(1){
        recv(newSocket, buffer, sizeof(buffer), 0);
        printf("Message from client: %s", buffer);
        printf("Etner message for client: ");
        fgets(buf, sizeof(buf), stdin);
        printf("Message sent to client");
        strcpy(buffer, buf);
        send(newSocket, buffer, sizeof(buffer), 0);
    }

    return 0;
}