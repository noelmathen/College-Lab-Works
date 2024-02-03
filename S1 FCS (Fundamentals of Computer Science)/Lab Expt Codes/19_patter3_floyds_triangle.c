/* Floyo's Triangle */
#include<stdio.h>
void main()
{
	int n,i=1,j=1,s;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	printf("\n");
	 while(i<=n)
	  {
	   s=1;
	    while(s<=i)
	     {
	      printf(" %d",j);
	      j+=1;
	      s+=1;
	     }
	 i+=1;
	 printf("\n");
	  }
}
