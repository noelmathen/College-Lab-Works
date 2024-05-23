#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
    int welcomeSocket, newSocket;
    char buffer[1024], str[1024];
    struct sockaddr_in serverAddress, serverStorage;
    socklen_t addr_size;

    welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2011);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddress.sin_zero, '\0', sizeof(serverAddress.sin_zero));

    bind(welcomeSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

    if(listen(welcomeSocket, 5)==0)
        printf("Listening");
    else
        printf("Error");

    addr_size = sizeof(serverStorage);
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

    int recvlen = recv(newSocket, buffer, strlen(buffer), 0);
    buffer[recvlen] = '\0';
    FILE *fp = fopen(buffer, "r");

    while(fgets(str, sizeof(str), fp)!=NULL){
        send(newSocket, str, strlen(str), 0);
    }

    fclose(fp);
    return 0;
}