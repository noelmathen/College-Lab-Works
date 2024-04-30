//TCP ECHO Client
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    addr_size = sizeof serverAddr;

    if(connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size) == -1){
        perror("Connect Failed. Error\n");
        return 1;
    }
    puts("Connected\n");

    while(1){
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);
        printf("Sending message to server\n");
        send(clientSocket, buffer, strlen(buffer), 0);
        recv(clientSocket, buffer, 1024, 0);
        printf("Echo from server: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer)); // Clear buffer for next message
    }

    return 0;
}
