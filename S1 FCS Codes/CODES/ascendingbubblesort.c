/* Acsending bubble sort */
#include<stdio.h>
#include<stdlib.h>
void main()
{
		int i, j, k, n, temp;
		int a[100];
		printf("Enter number of elements to be sorted: ");
		scanf("%d",&n);
		for(k=0;k<n;k++)
		{
			printf("Enter the element: ");
			scanf("%d",&a[k]);
		}
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("Pass %d:  ",j+1);
			for(i=0;i<n;i++)
			{
				if(a[i]>a[i+1])
				{
				  temp=a[i];
				  a[i]=a[i+1];
				  a[i+1]=temp;
				}
		  printf("%d\t",a[i]);
			}
		printf("\n");
		}
		printf("\n\n");
		printf("The sorted elements in ascending order are: ");
		for(i=0;i<n;i++)
		{
	      printf("%d ",a[i]);
	    }
}
