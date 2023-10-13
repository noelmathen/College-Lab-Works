#include<stdio.h>
#include<stdlib.h>
struct node
	{
		int data;
		struct node *next;
	};

	struct node *head=NULL, *pos=NULL, *tail=NULL;
	int ch, entry;

	void insend()
	{
		printf("Enter the element: ");
		scanf("%d",&entry);
		if(head=NULL)
		{
			head=(struct node*)malloc(sizeof(struct node));
			head->data=entry;
			head->next=NULL;
			pos=head;
			tail=head;
		}
		else
		{
			tail->next=(struct node*)malloc(sizeof(struct node));
			tail=tail->next;
			tail->data=entry;
			tail->next=NULL;
		}
	}


	void display()
	{
		pos=head;
		if(head==NULL)
		{
			printf("The list is empty!\n");
		}
		else
		{
			printf("The list is:  ");
			while(pos!=NULL)
			{
				printf("  %d",pos->data);
				pos=pos->next;
			}
		}
	}

	void ext()
	{
		printf("SHERYENNA :)\n");
		exit(0);
	}





void main()
{	
	
	printf("\n\n************SINGLY LINKED LIST************\n\n");
	printf("The options are:- \n\n1. INSERT(at end)\n2. INSERT(at any position)\n3. DELETE(from any position)\n4. SEARCH\n5. COUNT\n6. DISPLAY\n7. EXIT\n");

	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				insend();
				break;
			}
			
			case 6:
			{
				display();
				break;
			}
			case 7:
			{
				ext();
				break;
			}
		}

	}
}