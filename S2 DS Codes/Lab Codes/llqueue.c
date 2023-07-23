#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head=NULL, *pos=NULL, *tail=NULL, *temp, *del;
int ch, entry, number=0, i=0;

int isempty()
{
	if(head==NULL)
		return 1;
	else
		return 0;
	
}
void enqueue()
{
	printf("Enter the element to be inserted: ");
	scanf("%d",&entry);
	if(head==NULL)
	{
	  head=(struct node*)malloc(sizeof(struct node));
	  head->data=entry;
	  pos=head;
	  tail=head;
	}
	else
	{
    tail->next=(struct node*)malloc(sizeof(struct node));
    tail=tail->next;
    tail->data=entry;
	}
}

void dequeue()
{
	if(head==NULL)
  {
    printf("QUEUE UNDERFLOW! CANNOT DELETE!\n");
  }
  else
  {
    temp=head;
    head=head->next;
    printf("The element delted is: %d\n",temp->data);
    free(temp);
	}
}

void display()
{
	if(isempty())
	{
		printf("QUEUE UNDERFLOW!\n");
	}
	else
	{
		pos=head;
		printf("|");
		while(pos!=NULL)
		{
				printf(" %d |",pos->data);
				pos=pos->next;
		}
		printf("\n");
	}
}

void main()
{
	int ch;
	printf("\n*********QUEUE USING LINKED LIST*********\n\n");
	printf("MENU:- \n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
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
