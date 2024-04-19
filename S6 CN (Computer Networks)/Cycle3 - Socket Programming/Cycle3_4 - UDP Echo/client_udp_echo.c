//UDP ECHO CLIENT
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 2000
#define BUFFER_SIZE 1024

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    if ((clientSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) == -1) {
        perror("Invalid address/ Address not supported");
        return 1;
    }

    while (1) {
        // Read message from user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send message to server
        if (sendto(clientSocket, buffer, strlen(buffer), 0, (const struct sockaddr *)&serverAddr, addrLen) == -1) {
            perror("Send failed");
            return 1;
        }

        // Receive echo from server
        int recvBytes = recvfrom(clientSocket, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (recvBytes == -1) {
            perror("Receive failed");
            return 1;
        }

        buffer[recvBytes] = '\0'; // Null-terminate the received data
        printf("Echo from server: %s\n", buffer);
    }

    // Close socket
    close(clientSocket);

    return 0;
}
