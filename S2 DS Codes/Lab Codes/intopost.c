#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define n 100
int top;

char infix[n],postfix[n];

void push (char x)
{
	top++;
	postfix[top]=x;
}

char pop()
{
	if(top== -1)
	{
		return 1;
	}
	else
	{
		return postfix[top--];
	}
}

int priority(char x)
{
	if(x== '+' ||  x== '-')
	{
		return 1;
	}
	if (x== '*' || x== '/')
	{
		return 2;
	}
	return 0;
}


void main()
{
 while(1)
 {
	char *ptr, x;
	printf("\nENTER THE INFIX EXPRESSION TO BE CONVERTED: ");
	scanf("%s",infix);
	printf("\n");
	ptr=infix;
	printf("The postfix expression is: ");
	while (*ptr!= '\0')
	{
		if (isalnum(*ptr))
		{
			printf("%c",*ptr);
		}
		else
		{
			while (priority(postfix[top]) >= priority (*ptr))
			{
				printf("%c",pop());
			}
			push(*ptr);
		}
			ptr++;
	}
	while(top != -1)
	{
		printf("%c",pop());
	}
	printf("\n");
 }
}
