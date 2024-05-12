#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create the socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891); // Assuming port 7891
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming server is localhost
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    // Connect to the server
    addr_size = sizeof serverAddr;
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, addr_size) < 0) {
        perror("Connect failed. Error");
        exit(EXIT_FAILURE);
    }
    printf("Connected\n");

    // Prompt the user to enter the filename
    char buffer[1024];
    printf("Enter the filename: ");
    scanf("%s", buffer);

    // Send the filename to the server
    send(clientSocket, buffer, strlen(buffer), 0);

    // Receive and display file contents from the server
    char received_buffer[1024];
    int bytes_received = recv(clientSocket, received_buffer, sizeof(received_buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving file contents");
        exit(EXIT_FAILURE);
    }
    printf("Received file contents:\n%s\n", received_buffer);

    // Close the socket
    close(clientSocket);

    return 0;
}

