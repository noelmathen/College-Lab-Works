#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <server_IP>\n", argv[0]);
    exit(1);
  }

  int client_socket;
  struct sockaddr_in server_address;

  // Create a UDP socket
  if ((client_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket() failed");
    exit(1);
  }

  // Set up server address structure
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  inet_pton(AF_INET, argv[1], &server_address.sin_addr); // Convert server IP from string

  char message[BUFFER_SIZE];

  while (1) {
    printf("Enter message to send (or 'EXIT' to quit): ");
    fgets(message, BUFFER_SIZE, stdin);

    // Remove trailing newline character
    message[strcspn(message, "\n")] = '\0';

    // Send the message to the server
    if (sendto(client_socket, message, strlen(message), 0,
               (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
      perror("sendto() failed");
      exit(1);
    }

    if (strcmp(message, "EXIT") == 0) {
      break;
    }

    // **Optional:** You can uncomment the following lines to receive messages
    // from the server and print them on the client side.

    // int bytes_received = recvfrom(client_socket, message, BUFFER_SIZE - 1, 0, NULL, NULL);
    // if (bytes_received > 0) {
    //   message[bytes_received] = '\0';
    //   printf("Received message from server: %s\n", message);
    // }
  }

  // Close the socket
  close(client_socket);

  return 0;
}