/* To check whether a number is perfect or not */
#include<stdio.h>
void main()
{
	int a, sum=0, i=1;
	printf("Enter any number: ");
	scanf("%d",&a);
	while(i<a)
	{
		if(a%i==0)
		{
		sum=sum+i;
		}
		i=i+1;
	}
	if(sum==a)
	{
	printf("The entered number is a perfect number!\n");
	}
	else
	{
	printf("The entered number is not a perfect number!\n");
	}
}
		
