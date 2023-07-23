#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

void main()
{
    printf("\n******SHARED MEMORY: WRITESHM******\n");
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	key_t key=ftok("shmfile",65);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	printf("\nKey of the shared memory is: %d",shmid);
	shared_memory=shmat(shmid, NULL,0);
	printf("\nEnter data to wrtie to shared memory: ");
	fgets(buff,100,stdin);
	strcpy(shared_memory, buff);
	printf("\nThe data written is : %s", (char*) shared_memory);
	printf("\n");
}
