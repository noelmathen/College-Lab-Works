//udp client code
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
    socklen_t addr_size;
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0); 
    if (clientSocket < 0) {
        perror("socket creation failed");
        return 1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2004); 
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    addr_size = sizeof serverAddr;

    while (1) {
        printf("Enter the message: ");
        fgets(buf, 1024, stdin);
        printf("Message sent to server\n");
        
        strcpy(buffer, buf);
        sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, addr_size);
        
        int recv_size = recvfrom(clientSocket, buffer, 1024, 0, NULL, NULL);
        if (recv_size < 0) {
            perror("recvfrom failed");
            return 1;
        }
        buffer[recv_size] = '\0';// Null-terminate the received data
        printf("Reply from server: %s\n", buffer);
    }
    return 0;
}
