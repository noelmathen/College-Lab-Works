//linear search
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int i, key, num, count=0, n=100;
	int arr[n];
	
	printf("\nEnter total number of elements(less than 100): ");
	scanf("%d",&num);
	
	printf("\nThe randomly generated elements are: ");
	for(i=0;i<num;i++)
	{
		arr[i]=rand()%100;
		printf("%d  ",arr[i]);
	}
	
	printf("\n\nEnter the element to be searched: ");
	scanf("%d",&key);
	printf("\n");
	gettimeofday(&t0, NULL);
	for(i=0;i<num;i++)
	{
		if(arr[i]==key)
		{
			printf("%d is found at the position %d\n",key,i);
			count++;
		}
	}
	if(count==0)
	printf("Element not found!\n");
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nFunction executed in %f milisseconds\n", elapsed);
}

