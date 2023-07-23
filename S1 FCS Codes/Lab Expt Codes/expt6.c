/* To convert a decimal number into binary equivalent */
#include<stdio.h>
void main()
{
	int a, b, sum=0, i=1;
	printf("Enter any number: ");
	scanf("%d",&a);
	while(a>0)
	{
	b=a%2;
	sum=sum + (b*i);
	a=a/2;
	i=i*10;
	}
	printf("The binary equivalent is: %d\n",sum);
}
	
