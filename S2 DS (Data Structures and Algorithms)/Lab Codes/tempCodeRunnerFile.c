/* Acsending bubble sort */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void main()
{
		int i, j, n, temp;
		int a[100];
		printf("Enter number of elements to be sorted: ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter the element: ");
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
			printf("Pass %d:  ",i+1);
			for(j=0;j<n-1;j++)
			{
                bool swapped=false;
				if(a[j]>a[j+1])
				{
				  temp=a[j];
				  a[j]=a[j+1];
				  a[j+1]=temp;
                  swapped=true;
				}
                if(swapped==false)
                {
                    return;
                }
		 	 printf("%d\t",a[j]);
		  	}
		  	printf("%d",a[j]);
		 printf("\n");
		}
		printf("\n\n");
		printf("The sorted elements in ascending order are: ");
		for(i=0;i<n;i++)
	  {
	    printf("%d ",a[i]);
	  }
	printf("\n");
}

