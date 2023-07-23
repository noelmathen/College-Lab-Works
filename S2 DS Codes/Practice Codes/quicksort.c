#include<stdio.h> 
#include<stdlib.h>
#define num 1000
int arr[num];

int partition(int a[], int low, int high)
{
    int i, j, pivot,temp1,temp2;
    pivot=arr[high];
    i=low-1;
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp1=a[i];
            a[i]=a[j];
            a[j]=temp1;
        }
    }
    temp2=a[i+1];
    a[i+1]=a[high];
    a[high]=temp2;
    return i+1;
}

void quicksort(int arr[], int left, int right)
{
    if(left<right)
    {
        int pIndex=partition(arr,left,right);
        quicksort(arr,left,pIndex-1);
        quicksort(arr,pIndex+1,right);
    }
}

void main()
{
    int i, n;
    printf("\n********QUICK SORT********\n\n");
    printf("Enter the number of elements to be generated: ");
    scanf("%d",&n);
    printf("\nThe randomly generated array is: ");
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100;
        printf("%d  ",arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\n\nThe sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
