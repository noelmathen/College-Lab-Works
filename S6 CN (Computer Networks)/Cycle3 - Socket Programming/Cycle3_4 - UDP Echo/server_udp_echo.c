//UDP ECHO SERVER
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2000
#define BUFFER_SIZE 1024

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(serverSocket, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        return 1;
    }

    printf("UDP echo server is listening on port %d...\n", PORT);

    while (1) {
        // Receive message from client
        int recvBytes = recvfrom(serverSocket, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&clientAddr, &addrLen);
        if (recvBytes == -1) {
            perror("Receive failed");
            return 1;
        }

        printf("Message from client: %s\n", buffer);

        // Echo message back to client
        if (sendto(serverSocket, buffer, recvBytes, 0, (const struct sockaddr *)&clientAddr, addrLen) == -1) {
            perror("Send failed");
            return 1;
        }

        printf("Echo sent to client\n");
    }

    // Close socket
    close(serverSocket);

    return 0;
}
