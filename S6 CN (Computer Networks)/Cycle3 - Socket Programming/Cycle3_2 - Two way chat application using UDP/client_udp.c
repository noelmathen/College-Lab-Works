//client side udp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 
#define PORT 2000
#define MAX_BUFFER_SIZE 1024

int main() {
    int clientSocket;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddr;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    while (1) {
        // Send message to server
        printf("Enter message to server: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        if (sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        // Receive response from server
        if (recvfrom(clientSocket, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL) == -1) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }
        printf("Message from server: %s\n", buffer);
    }

    // Close socket
    close(clientSocket);

    return 0;
}
