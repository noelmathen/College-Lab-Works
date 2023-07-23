
/* Write a C program to perform swapping of two numbers using function with Call by Reference */
#include<stdio.h>
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void main()
{
	int x,z;
	printf("Enter two numbers: ");
	scanf("%d%d",&x,&z);
	swap(&x,&z);
	printf("\nThe swapped numbers are %d and %d",x,z);
    printf("\n");
}

