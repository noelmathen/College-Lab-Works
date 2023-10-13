/* Write a program to copy elements in one array to another in reverse order */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100],b[100], n, i, z;
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
	
	for(i=0; i<=z,n>0; i++)
	{
	 z=n;
	 b[i]=a[n-1];
	 printf("%d ",b[i]);
	 n--;
	}
	printf("\n");
}

