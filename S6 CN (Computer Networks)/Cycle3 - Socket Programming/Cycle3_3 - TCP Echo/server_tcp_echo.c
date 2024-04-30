//TCP ECHO Server
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    bind(welcomeSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if (listen(welcomeSocket,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    addr_size = sizeof(clientAddr);
    newSocket = accept(welcomeSocket, (struct sockaddr*)&clientAddr, &addr_size);

    while (1){
        recv(newSocket, buffer, sizeof(buffer), 0);
        printf("Message from client: %s\n", buffer);
        printf("Echoing message back to client\n");
        send(newSocket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer)); // Clear buffer for next message
    }

    return 0;
}
