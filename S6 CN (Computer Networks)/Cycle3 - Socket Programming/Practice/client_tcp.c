#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
    int clientSocket;
    char buf[1024], buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memeset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    addr_size = sizeof(serverAddr);
    if(connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)==-1){
        printf("Conncetion failed");
        return 1;
    }
    printf("COnnection successful");

    while (1)
    {
        fgets(buf, 1024, stdin);
        strcpy(buffer, buf);
        send(clientSocket, buffer, strlen(buffer), 0);
        
    }
    

    return 0;
}