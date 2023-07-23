//Selection Sort

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdlib.h>
#define n 100

void main()
{
	int num, i, j, min;
	int arr[n], temp;
	printf("\n*****SELECTION SORT*****\n\n");
	printf("\nEnter total number of elements to be sorted(less than 100): ");
	scanf("%d",&num);
	printf("\nThe randomly generated elements are: ");
	for(i=0;i<num;i++)
	{
		arr[i]=rand()%100;
		printf("%d  ",arr[i]);	
	}// Functions to Print Elements of Array
	
	printf("\n");
	
	for(i=0;i<num-1;i++)
	{
		min=i;
		for(j=i+1;j<num;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}	
		}
		if(min!=i)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	printf("\nThe sorted elements are: ");
	for(i=0;i<num;i++)
	{
		printf("%d  ",arr[i]);
	}
}
