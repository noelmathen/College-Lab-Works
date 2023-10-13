#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
# define n 5

int top=-1;
int stack[n];

void push(int x)
{
	stack[++top]=x;
}

int  pop()
{
	return stack[top--];
	return 0;
}

void main()
{
 while(1)
 {
	char exp[20];
	char *ptr;
	int n1,n2,n3,num;
	printf("Enter the expression :");
	scanf("%s",exp);
	ptr=exp;
	while (*ptr !='\0')
	{
		if (isdigit(*ptr))
		{
			num=*ptr -48;
			push(num);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(*ptr)
			{
				case '+':
					 n3=n1 +n2;
					 break;
				case '-':
					n3= n1 - n2;
					break;
				case '*':
					n3 =n1 * n2;
					break;
				case '/':
					n3 = n1/n2;
					break;
			}
			push (n3);
		}
		ptr++;
	}
	printf("The evaluated expression %s  is : %d\n\n",exp,pop());
 }
}
