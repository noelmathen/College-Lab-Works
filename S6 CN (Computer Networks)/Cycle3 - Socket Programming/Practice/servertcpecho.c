#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAdress, clientAdress;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(2000);
    serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAdress.sin_zero, '\0', sizeof(serverAdress.sin_zero));

    bind(welcomeSocket, (struct sockaddr *) &serverAdress, sizeof(serverAdress));

    if(listen(welcomeSocket, 5)==0)
        printf("\nListening: ");
    else
        printf("Error");

    addr_size = sizeof(clientAdress);
    newSocket =  accept(welcomeSocket, (struct sockaddr *) &clientAdress, &addr_size);

    while (1)
    {
        // fgets(buffer, sizeof(buffer), stdin);
        recv(newSocket, buffer, sizeof(buffer), 0);
        printf("received from client: %s: ", buffer);
        printf("Echoing message back to client\n");
        send(newSocket, buffer, strlen(buffer), 0);
        memset(buffer, 0 ,sizeof(buffer));
    }
    return 0;
}