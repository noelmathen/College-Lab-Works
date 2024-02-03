/* Program to find the roots of a quadratic equation and to classify them as real, distinct, equal and imaginary */
#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,c,r1,r2,d;
	printf("For the equation ax^2 + bx + c,\n");
	printf("Enter the value of a: ");
	scanf("%d",&a);
	printf("Enter the value of b: ");
	scanf("%d",&b);
	printf("Enter the value of c: ");
	scanf("%d",&c);
	
	d=sqrt(b*b-4*a*c);
	r1=(-b+d)/2*a;
	r2=(-b-d)/2*a;
	printf("The first root is : %d\n",r1);
	printf("The second root is: %d\n",r2);
	
	if(b*b-4*a*c>0)
	{
	printf("The roots are real and distinct!\n");
	}
	else if(b*b-4*a*c==0)
	{
	printf("The roots are equal!\n");
	}
	else
	{
	printf("The roots are imaginary!\n");
	}
}
