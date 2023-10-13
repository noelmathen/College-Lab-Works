/* To find the divisors of a number */
#include<stdio.h>
void main()
{
	int a, c, i=1;
	printf("Enter any number: ");
	scanf("%d",&a);
	while(i<=a)
	{
	c=a%i;
		if(c==0)
		{
		printf("%d\n",i);
		i=i+1;
		}	
		else
		{
		i=i+1;
		}

	}
}
