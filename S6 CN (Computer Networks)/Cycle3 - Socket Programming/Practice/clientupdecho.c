#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
	int clientSocket;
	char buffer[1024];
	char  buf[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_in serverStorage;
	socklen_t addr_size;
	
	clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverStorage);
	
	
	while(1){
		int recvlen = recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) &serverStorage, &addr_size);
		if(recvlen == -1){
			perror("\nMessage not received");
			return 1;
		}
		buffer[recvlen] = '\0';
		printf("\nMessage received from client: %s", buffer);
		sendto(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *) & serverStorage, addr_size);
	}
	return 0;
}