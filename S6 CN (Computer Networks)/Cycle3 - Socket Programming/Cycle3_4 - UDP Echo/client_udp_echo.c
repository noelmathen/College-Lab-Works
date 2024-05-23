#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(){
	int clientSocket;
	char buffer[1024];
	char buf[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2000);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverAddr);
	
	while(1){
		printf("\nEnter message for client: ");
		fgets(buf, 1024, stdin);
		strcpy(buffer, buf);
		printf("\nMessage sent to client");
		sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *) &serverAddr, addr_size);
		int recvlen = recvfrom(clientSocket, buffer, 1024, 0, NULL, NULL);
		buffer[recvlen] = '\0';
		printf("\nReply from server: %s", buffer);
	}
	return 0;
}