#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer
{
	long msg_type;
	char msg_text[100];
}message;

void main()
{
    printf("\n******MESSAGE QUEUS: READING DATA DATA******\n");
	key_t key=ftok("progfile", 65);
	int msgid=msgget(key, 0666 | IPC_CREAT);
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	printf("Data received is %s", message.msg_text);
	msgctl(msgid, IPC_RMID, NULL);
}
