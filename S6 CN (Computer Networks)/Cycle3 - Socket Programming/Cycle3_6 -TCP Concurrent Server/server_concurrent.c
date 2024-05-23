#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/socket.h>

void handle_client(int clientSocket, int clientNumber){
	char buffer[1024];
	char response[1024];
	ssize_t responsebytes;
	
	while((responsebytes=recv(clientSocket, buffer, 1024, 0))>0){
		buffer[responsebytes] = '\0';
		printf("\nClient %d's message: %s", clientNumber, buffer);
		printf("\nEnter the response: ");
		fgets(response, 2048, stdin);
		printf("\nResponse sent");
		send(clientSocket, response, strlen(response), 0);
		if(responsebytes==0)
			printf("\nClient %d disconnected", clientNumber);
		else
			printf("\nConnection error");
	}
}

int main(){
	int welcomeSocket, clientSocket;
	//no chars. they are in function
	struct sockaddr_in serverAddr;
	struct sockaddr_in serverStorage;
	socklen_t addr_size;
	addr_size = sizeof(serverAddr);
	int clientNumber = 1; //initializing
	
	welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	
	if(listen(welcomeSocket, 5)==-1){
		perror("\nError");
		return 1;
	}
	
	puts("\nListening...");
	
	while(1){
		clientSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);
		printf("\nNew client connected. Client number: %d", clientNumber);
		
		pid_t pid = fork();
		if(pid==-1){
			printf("\nAccept failed");
			close(clientSocket);
			continue;
		}
		else if(pid==0){
			close(welcomeSocket);
			handle_client(clientSocket, clientNumber);
			exit(0);
		}
		else{
			close(clientSocket);
			clientNumber++;
		}
	}
	return 0;
}