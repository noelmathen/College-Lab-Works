#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(){
	int clientSocket;
	char buffer[1024];
	char buf[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(AF_INET, SOCK_DGRAM, 0); //SOCK_DGRAM
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverAddr);
	
	//No connection checks
	
	while(1){
		printf("\nEnter the message: ");
		fgets(buf, 1024, stdin);
		printf("\nMessage is sent to server");
		strcpy(buffer, buf);
		sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *) &serverAddr, addr_size);
		int recvlen = recvfrom(clientSocket, buffer, 1024, 0, NULL, NULL);
		if(recvlen == -1){
			perror("\nReceive failed");
			return 1;
		}
		buffer[recvlen] = '\0';
		printf("\nMessage from server: %s", buffer);
	}
	return 0;
}