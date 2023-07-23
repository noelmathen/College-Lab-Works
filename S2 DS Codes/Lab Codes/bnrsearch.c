//binary search
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define n 100

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int i, j, key, num, min, temp, count=0;
int a[n];

void selectionsort(int arr[])
{
	for(i=0;i<=(num-2);i++)
		{
			min=i;
			for(j=i+1;j<=(num-1);j++)
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
}

void binarysearch(int arr[], int number)
{ 
	int low=0, high=number-1, mid, flag=0;
	printf("\n\nEnter the element to be searched: ");
	scanf("%d",&key);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
		{
			flag++;
			break;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	
	if(flag==0)
	{
		printf("\nElement not found!\n");
	}
	else
	{
		printf("%d was found at the position %d",key,mid);
	}
	printf("\n");
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	printf("\nEnter total number of elements(less than 100): ");
	scanf("%d",&num);
	
	printf("\nThe randomly generated elements are: ");
	for(i=0;i<num;i++)
	{
		a[i]=rand()%100;
		printf("%d  ",a[i]);
	}
	selectionsort(a);
	printf("\n\nThe sorted elements are: ");
	for(i=0;i<num;i++)
	{
		printf("%d  ",a[i]);
	}
	
	gettimeofday(&t0, NULL);
	binarysearch(a,num);
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nFunction executed in %f milisseconds\n", elapsed);
}
