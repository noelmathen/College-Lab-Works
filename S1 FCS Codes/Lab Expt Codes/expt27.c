/* To calculate the scalar product of elements in an array ( c[0] = scalar_value * a[0] ) */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100], c[100], n, s, i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	if(n>100)
	{
	 printf("OUT OF BOUND!\n");
	 exit (0);
	}
	
	for(i=0; i<n; i++)
	{
	 printf("Enter the element: ");
	 scanf("%d",&a[i]);
	}
	
	printf("Enter the scalar_product value: ");
	scanf("%d",&s);
	
	for(i=0; i<n; i++)
	{
	 c[i] = a[i] * s;
	 printf("%d ",c[i]);
	}
	printf("\n");
}

