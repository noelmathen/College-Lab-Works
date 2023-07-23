/* Descending selection sort */
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, k, n, l, minpos=i, temp;
    int a[100];
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);
    for(k=0;k<n;k++)
    {
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    for(j=0;j<n-1;j++)
    {
        minpos=j;
        printf("Pass %d:  ",j+1);
        for(i=1;i<n;i++)
        {
            if(a[minpos]>a[i])
            {
                minpos=i;
            }
        }
        printf("\n");
        temp=a[minpos];
        a[minpos]=a[j];
        a[j]=temp;
    }
    printf("The entered elements in descending order are: ");
    for(l=0;l<n-1;l++)
    {
        printf("%d",a[l]);
    }
}
