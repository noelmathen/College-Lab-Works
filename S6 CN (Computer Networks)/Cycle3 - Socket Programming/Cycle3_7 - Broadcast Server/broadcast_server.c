#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

// Define the maximum number of clients that can connect (adjust as needed)
#define MAX_CLIENTS 10

// Structure to store client information
typedef struct {
  int socket;
  struct sockaddr_in address;
} Client;

int main(int argc, char *argv[]) {
  if (argc < 1) {
    fprintf(stderr, "Usage: %s\n", argv[0]);
    exit(1);
  }

  int server_socket;
  struct sockaddr_in server_address;
  Client clients[MAX_CLIENTS]; // Array to store connected clients
  int num_clients = 0;

  // Create a UDP socket
  if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket() failed");
    exit(1);
  }

  // Set up server address structure
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
  server_address.sin_port = htons(PORT);

  // Bind the socket to the address
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("bind() failed");
    exit(1);
  }

  printf("Broadcast server started on port %d\n", PORT);

  char message[BUFFER_SIZE];

  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    // Receive message from a client
    int bytes_received = recvfrom(server_socket, message, BUFFER_SIZE - 1, 0,
                                  (struct sockaddr *) &client_address, &client_address_size);
    if (bytes_received == -1) {
      perror("recvfrom() failed");
      exit(1);
    }

    message[bytes_received] = '\0'; // Null-terminate the received message

    // Find or add the client to the list
    int client_found = 0;
    for (int i = 0; i < num_clients; i++) {
      if (clients[i].socket == client_address.sin_port) {
        client_found = 1;
        break;
      }
    }

    if (!client_found) {
      if (num_clients >= MAX_CLIENTS) {
        printf("Maximum number of clients reached\n");
        continue;
      }
      clients[num_clients].socket = client_address.sin_port;
      clients[num_clients].address = client_address;
      num_clients++;
    }

    printf("Received message from client %s:%d: %s\n",
           inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), message);

    // Broadcast the message to all connected clients (except the sender)
    for (int i = 0; i < num_clients; i++) {
      if (clients[i].socket != client_address.sin_port) {
        if (sendto(server_socket, message, strlen(message), 0,
                   (struct sockaddr *) &clients[i].address, sizeof(clients[i].address)) == -1) {
          perror("sendto() failed");
          exit(1);
        }
      }
    }

    // Check for "EXIT" message to quit
    if (strcmp(message, "EXIT") == 0) {
      break;
    }
  }

  // Close the socket and free resources
  close(server_socket);

  return 0;
}