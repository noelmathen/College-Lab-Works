#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(client_socket, buffer, sizeof(buffer));
        printf("Client: %s\n", buffer);
        write(client_socket, buffer, strlen(buffer));
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid[MAX_CLIENTS];
    int client_count = 0;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to IP and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        socklen_t client_len = sizeof(client_addr);

        // Accept connection from client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread for each client
        if (pthread_create(&tid[client_count++], NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        if (client_count >= MAX_CLIENTS) {
            client_count = 0;
            while (client_count < MAX_CLIENTS) {
                pthread_join(tid[client_count++], NULL);
            }
            client_count = 0;
        }
    }

    close(server_socket);
    return 0;
}

