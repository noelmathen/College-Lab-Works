#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define n 1000
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void main()
{	
	int i, j, k, num, key;
	int a[n];
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	printf("\n*****INSERTION SORT*****\n\n");
	printf("Enter the total number of elements to be sorted: ");
	scanf("%d",&num);
	printf("The randomly generated array is: ");
	for(i=0;i<num;i++)
	{
		a[i]=rand()%100;
		printf("%d  ",a[i]);
	}
	gettimeofday(&t0, NULL);
	
	for (i=1; i<num; i++) 
	{
		key = a[i];   
		for(j=i-1;j>=0 && a[j]>key;j--) 
		{
		    a[j+1] = a[j];
		}
		a[j+1] = key;
	}
	
	gettimeofday(&t1, NULL);
	
	printf("\n\nThe sorted array is: ");
	for(k=0;k<num;k++)
	{
		printf("%d  ",a[k]);
	}
	elapsed = timedifference_msec(t0, t1);
	printf("\n\nFunction executed in %f milisseconds\n\n", elapsed);
}
