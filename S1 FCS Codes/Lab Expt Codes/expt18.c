/* To print the following pattern 
				   1
				  232
				 34543
				4567654.....   
						 to a desired level */
#include<stdio.h>
void main()
{
	int a, b, c, n, i=1;
	printf("Enter the desired number of levles: ");
	scanf("%d",&n);
	while(i<=n)
	{
		a=(2*i)-1;
		b=n-i;
		c=i;
		while(b>0)
		 {
		  printf(" ");
		  b=b-1;
		 }
		 while(a>0)
		{
		  if(a>i)
		   {
		    printf("%d",c);
		    c+=1;
		   }
		  else
		   {
		    printf("%d",c);
		    c-=1;
		   } 
		   a-=1;
		}
		printf("\n");	
		i+=1;
	}
}
	
