/* To check whether a number is palindrome or not */
#include<stdio.h>
void main()
{
	int a, b,x, sum=0;
	printf("Enter any number: ");
	scanf("%d",&a);
	x=a;
	while(a>0)
	{
	b=a%10;
	sum=sum*10+b;
	a=a/10;
	}
	if(sum==x)
	{
	printf("The entered number is a palindrome!\n");
	}
	else
	{
	printf("The entered number is not a palindrome!\n");
	}

}
	
