#include<stdio.h>
#include<stdlib.h>
#define num 100
int arr[num], b[num], i, j, k, low, high, mid, n;
void merge(int arr[], int l, int m, int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int L[n1], R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        mid= (low+high)/ 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void main()
{
    printf("\n********MERGE SORT********\n\n");
    printf("Enter the number of elements to be generated: ");
    scanf("%d",&n);
    printf("\nThe randomly generated array is: ");
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100;
        printf("%d  ",arr[i]);
    }
    
    mergesort(arr, 0, n-1);
    
    printf("\n\nThe sorted array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
