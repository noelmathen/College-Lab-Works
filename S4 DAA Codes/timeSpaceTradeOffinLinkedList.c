#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL, *pos=NULL, *tail=NULL, *temp=NULL, *temp2=NULL, *del=NULL;
int ch, entry, i, size=0, count, large, tempdelete, delete=0;

void Insert()
{
	printf("Enter the element to be insterted: ");
	scanf("%d",&entry);
	if(head==NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = entry;
		head->next = NULL;
		pos = head;
		tail = head;
	}
	else
	{
		tail->next = (struct node*)malloc(sizeof(struct node));
		tail = tail->next;
		tail->data = entry;
		tail->next = NULL;
	}
	size++;
}

void Delete()
{

	clock_t DeletestartTime, DeleteendTime, nextStartTime, nextEndTime;
	double timeElapsed1, timeElapsed2;

	DeletestartTime = clock();
	printf("Enter the position of the element to be deleted: ");
	scanf("%d",&entry);
	if(head==NULL)
	{
		printf("LIST EMPTY! CANNOT DELETE!");
	}
	else
	{
		if(entry==0)
		{
			del=head;
			head = head->next;
			del->next=NULL;
			printf("The deleted element is: %d",del->data);
			tempdelete = del->data;
			free(del);
			size--;
			delete = 1;
		}
		else if(entry>0 && entry<size-1)
		{
			pos=head;
			for(i=0;i<entry-1;i++)
			{
				pos=pos->next;
			}
			temp = pos;
			del = temp->next;
			temp->next = temp->next->next;
			del->next=NULL;
			printf("The deleted element is: %d",del->data);
			tempdelete = del->data;
			free(del);
			size--;
			delete = 1;
		}
		else if(entry==size-1)
		{
			pos=head;
			for(i=0;i<entry-1;i++)
			{
				pos=pos->next;	
			}
			tail = pos;
			del = pos->next;
			tail->next = NULL;
			printf("The deleted element is: %d",del->data);
			tempdelete = del->data;
			free(del);
			size--;
			delete = 1;
		}
		else
		{
			printf("No element in the given position!");
		}
		DeleteendTime = clock();
		timeElapsed1 = (double)(DeleteendTime - DeletestartTime)/CLOCKS_PER_SEC;
		printf("\nThe time taken for deletion is: %fs\n",timeElapsed1);
		//next largest element
		nextStartTime = clock();
		large = head->data;
		pos = head;
		if(delete == 1)
		{
			while(pos!=NULL)	//finding largest element in the list
			{
				if(pos->data > large)
				{
					large = pos->data;
				}
				pos = pos->next;
			}
			if(tempdelete >= large)	//deleted element is greater than the largest element in the list
			{
				printf("\nThere is no element greater than %d\n",tempdelete);
			}
			else
			{
				pos = head;
				while(pos!=NULL)
				{
					if(pos->data > tempdelete && pos->data < large)
					{
						large = pos->data;
					}
					pos = pos->next;
				}
				printf("\nThe next greatest element in the list is : %d \n",large);	    
			}
		}
		nextEndTime = clock();
		timeElapsed2 = (double)(nextEndTime - nextStartTime)/CLOCKS_PER_SEC;
		printf("\nThe time taken for finding next largest number is: %fs\n",timeElapsed2);
	}
}

void Display()
{
	pos = head;
	printf("The list is: ");
	while(pos!=NULL)
	{
		printf("%d  ",pos->data);
		pos=pos->next;
	}
}

void main()
{
	int n;
	printf("\nEnter the number of elements in linked list: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = rand()%100;
		temp->next = NULL;
		if(head==NULL)
		{
			head=temp;
			tail=head;
			pos=head;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
		size++;
	}
	printf("\nLINKED LIST\n\n1. INSERT\t2. DELETE\t3. DISPLAY\t0.EXIT\n");
	while(1)
	{
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	Insert();
					break;
					
			case 2:	Delete();
					break;
					
			case 3:	Display();
					break;
					
										
			case 0:	printf("OHK BEI:))\n");
					exit(0);
					break;
					
			default:	printf("INVALID INPUT! TRY AGAIN!");
						break;
		}
	}
}
