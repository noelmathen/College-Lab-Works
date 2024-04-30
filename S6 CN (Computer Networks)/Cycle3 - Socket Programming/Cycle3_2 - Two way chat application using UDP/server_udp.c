//server side udp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 

#define PORT 2000
#define MAX_BUFFER_SIZE 1024

int main() {
    int serverSocket;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address and port
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive message from client
        if (recvfrom(serverSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&clientAddr, &addrLen) == -1) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }
        printf("Message from client: %s\n", buffer);

        // Send response to client
        printf("Enter message to client: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        if (sendto(serverSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&clientAddr, addrLen) == -1) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close socket
    close(serverSocket);

    return 0;
}
