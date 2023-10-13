#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void main()
{
    printf("\n******SHARED MEMORY: SHARED DATA******\n");
	void *shared_memory;
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key, 1024, 0666 | IPC_CREAT);
	printf("Key of shared memory is: %d",shmid);
	shared_memory=shmat(shmid, NULL, 0);
	printf("\nData from shared memory: %s", (char*)shared_memory);
	printf("\n");
}
