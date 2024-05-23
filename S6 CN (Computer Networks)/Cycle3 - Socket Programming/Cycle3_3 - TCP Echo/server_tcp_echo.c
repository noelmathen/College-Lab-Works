#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(){
	int welcomeSocket, newSocket;
	char buffer[1024]; //no buf
	struct sockaddr_in serverAddr;
	struct sockaddr_in serverStorage;
	socklen_t addr_size;
	
	welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = INADDR_ANY; //changed from inet_addr(127.0.0.1)
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverAddr);
	
	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	
	if(listen(welcomeSocket,5)==0)
		puts("\nListening");
	else
		perror("\nError");
	
	newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
	
	while(1){
		recv(newSocket, buffer, 1024, 0);
		printf("\nMessage received from client: %s", buffer);
		printf("\nMessage echo");
		send(newSocket, buffer, sizeof(buffer), 0); //no strcpy
		memset(buffer, 0, sizeof(buffer)); //add memset to clear buffer
	}
	return 0;	
}