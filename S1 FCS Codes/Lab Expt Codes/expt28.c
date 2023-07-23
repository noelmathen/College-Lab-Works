/* To perform the vector addition of two arrays ( c[0] = a[0] + b[0] ) */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a[100], b[100],c[100], m, n, i;
	printf("Enter number of elements for first array : ");
	scanf("%d",&m);
	if(m>100)
	{
	 printf("OUT OF BOUND!\n");
	 exit (0);
	}
	for(i=0; i<m; i++)
	{
	 printf("Enter the elements: ");
	 scanf("%d",&a[i]);
	}
	
	
	printf("Enter number of elements for second array: ");
	scanf("%d",&n);
	if(n>100)
	{
	 printf("OUT OF BOUND!\n");
	 exit (0);
	}
	for(i=0; i<n; i++)
	{
	 printf("Enter the elements: ");
	 scanf("%d",&b[i]);
	}
	
	for(i=0; i<m || i<n; i++)
	{
	 c[i] = a[i] + b[i];
	 printf("%d ",c[i]);
	}
	
	printf("\n"); 
}

