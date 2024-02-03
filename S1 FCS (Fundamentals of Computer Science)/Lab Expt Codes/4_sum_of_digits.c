/* To read an integer and calculate the sum of digits in it */
#include<stdio.h>
void main()
{
	int a, b, sum=0;
	printf("Enter any number: ");
	scanf("%d",&a);
	while(a>0)
	{
	b=a%10;
	sum=sum+b;
	a=a/10;
	}
	printf("The sum of the digits of the entered number is: %d\n",sum);
}
