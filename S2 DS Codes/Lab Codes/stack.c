#include<stdio.h>
#include<stdlib.h>
#define n 5
int stack[n], top=-1, entry;


int isfull()
{
	if(top==n-1)
		return 1;
	else
		return 0;
}

int isempty()
{
	if(top==-1)
	  return 1;
	else
	  return 0;
}

void push()
{
	if(isfull())
	{
		printf("STACK OVERFLOW!\n");
	}
	else
	{
		printf("Enter the element to be inserted: ");
		scanf("%d",&entry);	
		top++;
		stack[top]=entry;
	}
}

void pop()
{
	if(isempty())
	{
		printf("STACK UNDERFLOW!\n");
	}
	else
	{
		printf("The popped element is: %d\n",stack[top]);
		stack[top]=-1;
		top--;
	}
}
		
void display()
{
	int i;
	printf("The stack is: \n\n");
	for(i=top;i>=0;i--)
	{
		printf("| %d |\n",stack[i]);
		printf("----- \n");
	}
}

void stacktop()
{
	printf("The topmost element in the stack is %d and its position is %d",stack[top],top);
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
















