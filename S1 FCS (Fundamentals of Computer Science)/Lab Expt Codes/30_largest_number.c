/* To find the largest among ten numbers */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n, i, small, large;
	int a[10];
	
	for(i=0; i<10; i++)
	{
	 printf("Enter the element: ");
	 scanf("%d",&a[i]);
	}
	
	small=a[0];
	large=a[0];

	for(i=0; i<10; i++)
	{
	  if(a[i]>large)
	  {
	   large=a[i];
	  }
	  if(a[i]<small)
	  {
	   small=a[i];
	  }
	}
	 printf("The largest number is: %d\n",large);
	 printf("The smallest number is: %d\n",small);
}
