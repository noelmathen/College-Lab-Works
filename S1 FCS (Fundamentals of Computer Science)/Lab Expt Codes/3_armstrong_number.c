/* To check whether a given number is an armstrong number */
#include<stdio.h>
void main()
{
	int a, b, sum=0, c;
	printf("Enter any number: ");
	scanf("%d",&a);
	c=a;
	while(a>0)
	{
	b=a%10;
	sum=sum+(b*b*b);
	a=a/10;
	}
	if(sum==c)
	{
	printf("The entered number is an armstrong number!\n");
	}
	else
	{
	printf("The entered number is not an armstrong number!\n");
	}
}
