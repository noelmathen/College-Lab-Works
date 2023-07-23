/* To print the pyramidal pattern of asterisks to a desired levels */
#include<stdio.h>
void main()
{
	int n,i=0,j=0,s=0;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	while(i<n)
	{
		s=0;
		while(s<n-i-1)
		{
		printf(" ");
		s+=1;
		}
		
		j=0;
		while(j<i+1)
		{
		printf(" *");
		j+=1;
		}
		
		printf("\n");	
		i+=1;
	}
}
	
