#include<stdio.h>
void main()
{
	int i, j, k, n=5, temp, min, a[100];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
  	for(i=0;i<n;i++)
	{
		min=i;
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


	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	

}