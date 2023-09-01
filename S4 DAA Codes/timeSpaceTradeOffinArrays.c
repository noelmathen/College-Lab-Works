#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 1000000000
int a[size];

void nextLargest(int a[], int n, int temp)
{
	int i;
	//finding the largest element
		int large = a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]>large)
			{
				large = a[i];	
			}
		}
		
		//finding the element just greater than the deleted element
		if(temp >= large)	//deleted element is greater than the largest element in the array
		{
			printf("\nThere is no element greater than %d!\n",temp);
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]>temp && a[i]<large)
				{
					large = a[i];// checks for the smallest largest element(element just greater than the deleted element)
				}
			}
			printf("\nThe next greatest element in the list is : %d \n",large);	    
		}
}


void delete(int a[], int n, int x)
{
	
	clock_t DeletestartTime, DeleteendTime, nextStartTime, nextEndTime;
	double timeElapsed1, timeElapsed2;
	int temp = a[x];// temporarily stores the deleted element
	if(x<n)
	{
		DeletestartTime = clock();
		for (int i=x;i<n;i++)
		{
			a[i]=a[i+1];
		}
		n=n-1;
		//printing the array after removal
		printf("\nThe elements in array after removal are:\n");
		for (int i=0;i<n;i++)
		{
			printf("%d  ",a[i]);
		}
		printf("\n");
		DeleteendTime = clock();
		timeElapsed1 = (double)(DeleteendTime - DeletestartTime)/CLOCKS_PER_SEC;
		printf("\nThe time taken for deletion is: %fs\n",timeElapsed1);
		
		
		nextStartTime = clock();
		nextLargest(a,n,temp);
		nextEndTime = clock();
		timeElapsed2 = (double)(nextEndTime - nextStartTime)/CLOCKS_PER_SEC;
		printf("\nThe time taken for finding next largest number is: %fs\n",timeElapsed2);
		
	}
	else
	{
		printf("\nOUT OF BOUND!\n");
	}
	
}

void main()
{
	int n, x, number;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&n);
	printf("The randomly generated array is:\n");
	for (int i=0;i<n;i++)
	{
		a[i] = rand()%100;
		printf("%d  ",a[i]);
	}
	printf("\n\nEnter the position of the element you want to delete: ");
	scanf("%d",&x);
	delete(a,n,x);
}

