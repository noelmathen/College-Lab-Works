#include<stdio.h>
#include<stdlib.h>
#define sizeofarray 1000

int num, n, i, j, temp, min, mid, key, a[sizeofarray];

void sort(int arr[], int n)
{
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
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

void binarysearch(int arr[], int n, int l, int h)
{
    printf("\n\nEnter the element to be searched");
    scanf("%d",key);
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==key)
        {
            
        }
    }
}


void main()
{
    printf("\nEnter the total number of elemetns: ");
    scanf("%d",&num);
    printf("\n\nThe randomly generated array is: ");
    for(i=0;i<num;i++)
    {
        a[i]=rand()%1000;
        printf("%d  ",a[i]);
    }
    sort(a,num);
    printf("\n\nThe sorted array is: ");
    for(i=0;i<num;i++)
    {
        printf("%d  ",a[i]);
    }
    binarysearch(a,num,0,num-1);

}