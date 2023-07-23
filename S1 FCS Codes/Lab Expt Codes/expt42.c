/* Write C programs that use both recursive and non-recursive functions to find the factorial of a given integer. */
#include<stdio.h>
int fac(int a)
{
	if (a==1 || a==0)
		return 1;
	else
		return a*fac(a-1);
}

int facto(int a)
{
	int b=1,i;
	for(i=1;i<=a;i++)
	{
		b=b*i;
	}
	return b;
}

void main()
{
	int a,b,c;
	printf("Enter a number: ");
	scanf("%d",&a);
	b=fac(a);
	c=facto(a);
	printf("Factorial by recursive method = %d\nFactorial by non-recursive method = %d",b,c);
    printf("\n");
}
