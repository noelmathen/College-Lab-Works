#include<stdio.h>
#include<stdlib.h>

struct node
    {
        int data;
        struct node *next;
    };

struct node *top=NULL, *pos=NULL, *new=NULL, *temp=NULL;
int ch, entry, number=0, i;

int isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void push()
{
  printf("Enter the element to be inserted: ");
  scanf("%d",&entry);
  if(top==NULL)
  {
    top=(struct node*)malloc(sizeof(struct node));
    top->data=entry;
  }
  else
  {
    new=(struct node*)malloc(sizeof(struct node));
    new->next=top;
    new->data=entry;
    top=new;
  }
  number++;
}

void pop()
{
	if(isempty())
	{
		printf("STACK UNDERFLOW!\n");
	}
	else
	{
		printf("The deleted element is: %d",top->data);
		top=top->next;
	}
	printf("\n");
}

void display()
{
	if(top==NULL)
	{
		printf("STACK UNDERFLOW! CANNOT DISPLAY!\n");
	}
	else
	{
		printf("\nThe stack is: \n");
		pos=top;
		while(pos!=NULL)
		{
				printf("\n| %d |",pos->data);
				printf("\n-----");
				pos=pos->next;
		}
	}
  printf("\n");     
}

void main()
{
	int ch;
	printf("\n*********STACK*********\n\n");
	printf("MENU:- \n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			{
				push();
				break;
			}
			
			case 2:
			{
				pop();
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
