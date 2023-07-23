/* To find the GCD of three numbers */
#include<stdio.h>
void main()
{
	int a, b, c, n=1, gcd;
	printf("Enter the first number  : ");
	scanf("%d",&a);
	printf("Enter the second number : ");
	scanf("%d",&b);
	printf("Enter the third number  : ");
	scanf("%d",&c);
	while(n<=a && n<=b && n<=c)
	{
		if(a%n==0 && b%n==0 && c%n==0)
		{
		 gcd=n;
		}
		n+=1;
	}
	printf("The GCD is: %d\n",gcd);
}
