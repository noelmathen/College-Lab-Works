/* To find the sum of the first fifteen positive numbers */
#include<stdio.h>
void main()
{
	int a=0,i=0,n=30;
	while(i<=n)
	{
	a=a+i;
	i=i+2;
	}
	printf("The sum of first fifteen positive even numbers is: %d\n",a);
}
