/* To search the position of a particular digit in a given number */
#include<stdio.h>
void lib()
{
	int a, b, n=1, c;
	printf("Enter any number: ");
	scanf("%d",&a);
	printf("Enter a single digit of the previously entered number: ");
	scanf("%d",&b);
	while(a>0)
	{
	c=a%10;
		if(c==b)
		{
		printf("The entered numbers place is %d\n",n);
		break;
		}
		else
		{
		a=a/10;
		n=n*10;
		}
	}
}
