/* To print the following pattern:-       1
					 1 1
					1 2 1
				       1 3 3 1
				      1 4 6 4 1
				       1 3 3 1
				        1 2 1
				         1 1
				          1 ............ 	   			
                        				to a desired level */
#include<stdio.h>
void main()
{
	int n,i=0,j,s=0,coeff,a,b;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	a=n+1/2;
	b=n-a;
	while(i<a)
	{
		s=a-1;
		while(s>i)
		{
		 printf(" ");
		 s-=1;
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
	
	i=i-2;
	while(i>=0)
	{
		s=b-(i-n);
		while(s>1)
		{
		 printf(" ");
		 s-=1;
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
		i-=1;
	}
}
