#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAdress;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(2000);
    serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAdress.sin_zero, '\0', sizeof(serverAdress.sin_zero));

    if (connect(welcomeSocket, (struct sockaddr *) &serverAdress, sizeof(serverAdress)) == -1){
        printf("Error in connection: ");
        return 1;
    }
    printf("Connected!");

    while (1)
    {
        printf("Sending message back to server\n");
        fgets(buffer, sizeof(buffer), stdin);
        send(newSocket, buffer, sizeof(buffer), 0);
        printf("received from client: %s: ", buffer);
        printf("Echoing message back to client\n");
        recv(newSocket, buffer, strlen(buffer), 0);
        memset(buffer, 0 ,sizeof(buffer));
    }
    return 0;
}