#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 100

struct msg_buffer
{
	long msg_type;
	char msg_text[100];
}message;

void main()
{
    printf("\n******MESSAGE QUEUS: WRITING DATA******\n");
	key_t key = ftok("progfile", 65);
	int msgid=msgget(key, 0666|IPC_CREAT);
	message.msg_type=1;
	printf("Write message to send: ");
	fgets(message.msg_text, MAX, stdin);
	msgsnd(msgid, &message, sizeof(message), 0);
	printf("The data is : %s", message.msg_text);
}
