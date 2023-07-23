//Bubble Sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 100

void main()
{	
	int i, j, k, num, temp;
	int a[n];
	printf("\n*****BUBBLE SORT*****\n\n");
	printf("Enter the total number of elements to be sorted: ");
	scanf("%d",&num);
	printf("The randomly generated array is: ");
	for(i=0;i<num;i++)
	{
		a[i]=rand()%100;
		printf("%d  ",a[i]);
	}
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			bool swapped=false;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=true;
			}
			if(swapped=false)
			{
				return;
			}
		}
	}
	printf("\n\nThe sorted array is: ");
	for(k=0;k<num;k++)
	{
		printf("%d  ",a[k]);
	}
}
