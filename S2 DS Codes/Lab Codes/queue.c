#include<stdio.h>
#include<stdlib.h>
#define n 5
int queue[n], front=-1, rear=-1, entry, i, size=0;

int isfull()
{
	if(rear==n-1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(front==-1 && rear==-1)
		return 1;
	else 
		return 0;
}

void enqueue()
{
	if(isfull())
	{
		printf("QUEUE OVERFLOW!\n");
	}
	else
	{
		printf("Enter the element to be inserted: ");
		scanf("%d",&entry);
		if(front==-1)
			front=0;
		rear++;
		queue[rear]=entry;
		size++;
	}
}

void dequeue()
{
	if(isempty())
	{
		printf("QUEUE UNDERFLOW!\n");
	}
	else
	{
		printf("The deleted element is: %d",queue[front]);
		front++;
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
	}
	printf("\n");
	size--;
}

void display()
{
	if(isempty())
	{
		printf("QUEUE UNDERFLOW, CANNOT DISPLAY!\n");
	}
	else
	{
		printf("The queue is: \n\n");
		printf("|");
		for(i=front;i<=rear;i++)
		{
			printf(" %d |",queue[i]);
		}
		printf("\n");
	}
}


void main()
{
	int ch;
	printf("\n*********QUEUE*********\n\n");
	printf("MENU:- \n\n1. ENQUE\n2. DEQUE	\n3. DISPLAY\n4. EXIT\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			{
				enqueue();
				break;
			}
			
			case 2:
			{
				dequeue();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
			
			case 4:
			{
				printf("OHK BEI!:)\n");
				exit(0);
			}
			
			default:
			{
				printf("INVALID INPUT!\n");
				break;
			}
		}
	}
}
