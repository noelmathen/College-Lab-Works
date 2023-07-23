/* To reverse a given number */
#include<stdio.h>
void main()
{
	int a, b, sum=0, i=1;
	printf("Enter any number: ");
	scanf("%d",&a);
	while(a>0)
	{
	b=a%10;
	sum=sum*10 + b;
	i=i*10;
	a=a/10;
	}
	printf("The reversed number is: %d\n",sum);
}
