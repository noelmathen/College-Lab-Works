/* Write a program to read n elements and print it in reverse order(using arrays) */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100], n, i;
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
	
	for(i=n-1; i>=0; i--)
	{
	 printf("%d ",a[i]);
	}
	printf("\n");
}

