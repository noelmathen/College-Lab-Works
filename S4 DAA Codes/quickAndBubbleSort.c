#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10000000
int a[size], b[size];

void printArray(int a[], int n)
{
	for(int i=0;i<n;i++)
    {
    	printf("%d  ",a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(a[j]<=pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;

}


void quickSort(int a[], int left, int right)
{
    if(left<right)
    {
        int pIndex=partition(a,left,right);
        quickSort(a,left,pIndex-1);
        quickSort(a,pIndex+1,right);
    }
}

void bubbleSort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
    {
    	for(int j=0;j<n-i-1;j++)
    	{
    		if(a[j]>a[j+1])
    		{
				swap(&a[j], &a[j+1]);
			}
    	}
    }
}

void main()
{
	int i, j, temp, n;
	clock_t start1, start2, end1, end2;
	double timeElapsed1, timeElapsed2;
	printf("COMPARISON BETWEEN BUBBLE SORT AND QUICK SORT\n\n");
	printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("The randomy generated array is: ");
    for(i=0; i<n; i++)
    {
        a[i]=rand()%100;//generates random array
        b[i]=a[i];
    }
    
    //BUBBLE SORT
    start1 = clock();
    bubbleSort(a,n);
    end1 = clock();
    timeElapsed1 = (double)(end1 - start1)/CLOCKS_PER_SEC;

    //QUICK SORT
    for(i=0; i<n; i++)	//refreshing array to random values
    {
        a[i]=b[i];
    }

    start2 = clock();
    quickSort(a,0,n-1);
    end2 = clock();
    timeElapsed2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
    
    printf("\nTime for bubble sort: %f",timeElapsed1);
    printf("\nTime for quick sort : %f\n",timeElapsed2);
    
    //writing into file
    FILE *fptr;
    fptr = fopen("/home/student/Documents/Noel Mathen/DAA LAB/sort.txt","a+");
    //fprintf(fptr,"%-15s %-15s %-15s", "Size", "Bubble", "Quick");
    fprintf(fptr,"%-15d %-15f %-15f\n",n,timeElapsed1, timeElapsed2);
    fclose(fptr);


    //the below commands are used to plot the graph in using GNUPLOT in ubuntu
	/*
    set terminal postscript     
    set out "sort.ps"   //if there is some kind of error like "terminal not set our something, or if the output is not showing, then execute these two lines 1st. then execute the rest of them"

	set autoscale
	set title "SORTING ALGORITHM COMPARISON"
	set xlabel "Input Size(n)"
	set ylabel "Time Taken(s)"
	set grid	
	set logscale
	set xrange [10:100000]
	plot "sort.txt" using 1:2 title "Bubble Sort" with lines, "sort.txt" using 1:3 title "Quick Sort" with lines
	*/
}
