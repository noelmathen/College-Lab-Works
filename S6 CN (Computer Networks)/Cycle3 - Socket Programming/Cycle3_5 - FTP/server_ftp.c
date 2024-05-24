#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
	int welcomeSocket, newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_in serverStorage;
	socklen_t addr_size;
	char str[150];
	FILE *fp;
	
	welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(2010);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	addr_size = sizeof(serverStorage);
	
	bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	
	if(listen(welcomeSocket, 5)==0){
		perror("\nListening");
	}
	
	newSocket = accept(welcomeSocket, (struct sockaddr *)&serverStorage, &addr_size);
	
	int recvlen = recv(newSocket, buffer, sizeof(buffer), 0);
	buffer[recvlen] = '\0';
	printf("\nFile name received: %s", buffer);
	fp = fopen(buffer, "r");
	if(fp==NULL)
		printf("\nFile cannot be opened");
		
	while(fgets(str, sizeof(str), fp)!=NULL)
		send(newSocket, str, strlen(str), 0);
	
	fclose(fp);
	return 0;
}