#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(){
	int clientSocket;
	char buffer[1024];
	char buf[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2010);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverAddr);
	
	if(connect(clientSocket, (struct sockaddr *)&serverAddr, addr_size)==-1){
		perror("\nConnection failed");
		return 1;
	}
	puts("\nConnected");
	
	printf("\nEnter filename: ");
	scanf("%s", buffer);
	
	send(clientSocket, buffer, strlen(buffer), 0);
	int recvlen = recv(clientSocket, buf, sizeof(buf), 0);
	buf[recvlen] = '\0';
	printf("\nReceived data: %s", buf);
	return 0;
}