/* To print the following pattern:-  1
				     *1
				     **2
				     ***3
				     ****5....
						to a desired number of level */
#include<stdio.h>
void main()
{
	int a=0,b=1,c=0,i=0,j=0,n;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	printf("%d",b);
	printf("\n");
	 while(i<n-1)
	  {
	   j=0;
	   while(j<i+1)
	    {
	     printf("* ");
	     j+=1;
	    }
       	   c=a+b;
	   a=b;
	   b=c;
	   printf("%d",c);
	   printf("\n");
	   i+=1; 
	  }
}
