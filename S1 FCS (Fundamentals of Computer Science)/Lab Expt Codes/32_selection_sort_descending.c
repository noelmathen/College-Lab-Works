/* Descending selection sorting*/
#include<stdio.h>
void main()
{
    int a[100],i,j,n,temp,min;
    printf("Enter number of elements to be sorted: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {  
        printf("Enter element: ");
        scanf("%d",&a[i]);
    }
    printf("\n");
    printf("The array is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\n**********************************");
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        min=i;
        printf("Pass %d: ",i+1);
        for(j=i+1;j<n;j++)
        {
            if(a[min]<a[j])
            {
               min=j;
            }
            
	    }
	    temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        for(j=0;j<n;j++)
        {
         printf("%d\t",a[j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Sorted elements: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
