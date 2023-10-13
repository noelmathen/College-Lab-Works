/* Pascal's Triangle */
#include<stdio.h>
void main()
{
	int n,i=0,j,s=0,coeff=1;
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
		
			if(j==0)
			{
			coeff=1;
			}
			else
			{
			coeff=coeff*(i-j+1)/j;
			}
		printf("%d ",coeff);
		j+=1;
		}
		
		printf("\n");	
		i+=1;
	}
}
