#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int clientSocket;
    char buffer[1024];
    char buf[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_in serverStorage;
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    addr_size = sizeof(serverStorage);


    while (1) {
        recvfrom(clientSocket, buffer, 1024, 0, (struct sockaddr *) &serverStorage, &addr_size);
        printf("Reply from Client > %s \n", buffer);
        printf("Enter the message :");
        fgets(buf, 1024, stdin);
        printf("Message sent to Client \n");
        strcpy(buffer, buf);
        sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) &serverStorage, addr_size);
    }
    return 0;
}