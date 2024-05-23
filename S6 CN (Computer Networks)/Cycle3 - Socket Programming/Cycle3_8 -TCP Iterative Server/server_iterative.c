#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main(){
	int welcomeSocket, newSocket;
	char buffer[1024];
	char buf[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_in serverStorage;
	socklen_t addr_size;
	
	welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	
	if(listen(welcomeSocket, 5)==0)
		puts("\nlistening\n");
	else
		perror("\nConnection failed");
		
	
	while(1){
		addr_size = sizeof(serverStorage); //inside while loop
		newSocket = accept(welcomeSocket, (struct sockaddr *) & serverStorage, &addr_size); //inside while loop
		
		memset(buffer, 0, sizeof(buffer));
		int recvlen = recv(newSocket, buffer, 1024, 0);
		if(recvlen == -1)
			perror("\nReceive failed");
		else{
			printf("\nMessage from client: %s", buffer);
			printf("\nEnter reply: ");
			fgets(buf, 1024, stdin);
			send(newSocket, buf, strlen(buf), 0);
			printf("\nMessage sent to client");
		}
	}
	return 0;
}