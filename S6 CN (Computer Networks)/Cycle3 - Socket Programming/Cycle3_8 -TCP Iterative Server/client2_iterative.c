#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
	int clientSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverAddr);
	
	if(connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)==-1){
		perror("\nConnection Failed");
		return 1;
	}
	puts("\nConnected");
	
	//no while loop
	printf("\nEnter message: ");
	fgets(buffer, 1024, stdin);
	send(clientSocket, buffer, sizeof(buffer), 0);
	printf("\nMessage sent");
	//recvlen integer to display message
	int recvlen = recv(clientSocket, buffer, 1024, 0);
	if(recvlen==-1)
		perror("\nReceive failed");
	else
		printf("\nMessage from server: %s", buffer);
	return 0;
}