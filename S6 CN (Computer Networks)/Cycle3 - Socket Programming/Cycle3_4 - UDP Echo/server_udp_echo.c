#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int welcomeSocket;
    char buffer[1024];
    char buf[1024];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    welcomeSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (welcomeSocket < 0) {
        perror("socket creation failed");
        return 1;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9999);
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    if (bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("bind failed");
        return 1;
    }

    printf("Listening...\n");
    addr_size = sizeof(clientAddr);

    while (1) {
        int recv_size = recvfrom(welcomeSocket, buffer, 1024, 0, (struct sockaddr *)&clientAddr, &addr_size);
        if (recv_size < 0) {
            perror("recvfrom failed");
            return 1;
        }
        buffer[recv_size] = '\0'; // Null-terminate the received data
        printf("Message from client: %s\n", buffer);

        // Echo back to the client
        sendto(welcomeSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&clientAddr, addr_size);
        printf("Echoed message to client: %s \n", buffer);
    }
    return 0;
}
