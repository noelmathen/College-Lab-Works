#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/*
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
*/
int partition(int arr[], int low, int high)
{
	
	int pivot = arr[high];
	
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		if (arr[j] < pivot) {
			
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	FILE *fptr;
	fptr = fopen("sort.dat","a+");
	 if(fptr == NULL)
	{
		printf("Error!");   
		exit(1);             
	}
	srand(time(NULL));  
	
	clock_t start_t, end_t;
	double bubble_t,quick_t;

	int arr[100000],arr1[100000],n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%10000;
		arr1[i]=arr[i];
	}
	
	start_t = clock();
	quickSort(arr1, 0, n - 1);
	end_t = clock();
	
	//printArray(arr1, n);
	
	quick_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	
	start_t = clock();
	bubbleSort(arr, n);
	end_t = clock();
	//printArray(arr, n);
	
	bubble_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	printf("\nTime taken for \nBubble sort: %f\nQuick sort: %f",bubble_t,quick_t);
	fprintf(fptr,"%d\t%f\t%f\n",n,bubble_t,quick_t);
   	fclose(fptr);
	return 0;
}

