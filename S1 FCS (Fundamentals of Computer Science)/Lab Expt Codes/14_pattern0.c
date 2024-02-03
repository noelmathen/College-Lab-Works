/* To print the following pattern
			*
		        **
		        ***
		        ****...........
 					to a desired levels */
#include<stdio.h>
void main()
{
	int n,i=0,j=0;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	while(i<n)
	{
		
		j=0;
		while(j<i+1)
		{
		printf("*");
		j+=1;
		}
		
		printf("\n");	
		i+=1;
	}
}
	
