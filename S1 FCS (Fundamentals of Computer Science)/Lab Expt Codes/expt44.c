/* Write a C program to perform vector addition (addition of two integer arrays) using function with Call by Reference. */
#include<stdio.h>

void vect(int *x,int *y,int *z,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		*(z+i)=(*(x+i)) + (*(y+i));
	}
	
}

int main()
{
	int n,i,d;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n],b[n],c[n];
	printf("\nEnter vec A: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter vec B: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	vect(a,b,c,n);
	
	printf("\nVec C is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");
}

