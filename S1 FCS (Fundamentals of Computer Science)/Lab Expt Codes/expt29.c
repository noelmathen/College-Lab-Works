/* To calculate the sum and average of n numbers */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int  n, i, z=0;
	float avg;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
		
	for(i=0; i<n; i++)
	{
	 printf("Enter the element: ");
	 scanf("%d",&a[i]);
	 z=z+a[i];
	}
	avg=(float)z/(float)n;
	printf("The sum of n numbers is    : %d\n",z);
	printf("The average of n numbers is: %0.2f\n",avg);
}

