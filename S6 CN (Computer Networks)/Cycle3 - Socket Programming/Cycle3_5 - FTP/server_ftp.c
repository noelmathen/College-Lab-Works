#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
    FILE *fp;
    char str[150];

    // Create the welcome socket
    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (welcomeSocket == -1) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891); // Assuming port 7891
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Bind the socket to the address
    if (bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed. Error");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(welcomeSocket, 5) == 0) {
        printf("Listening...\n");
    } else {
        printf("Error in listening\n");
        exit(EXIT_FAILURE);
    }

    // Accept connection
    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);

    // Receive filename from client
    recv(newSocket, buffer, sizeof(buffer), 0);
    printf("Filename received: %s\n", buffer);

    // Open file
    fp = fopen(buffer, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // Read and send file contents to client
    while (fgets(str, sizeof(str), fp) != NULL) {
        send(newSocket, str, strlen(str), 0);
    }

    // Close file and sockets
    fclose(fp);
    close(newSocket);
    close(welcomeSocket);

    return 0;
}

