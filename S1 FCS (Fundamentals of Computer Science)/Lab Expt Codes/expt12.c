/* To find the largest and smallest amoongs a list of numbers */
#include<stdio.h>
void main()
{
	int i=0,n,a,l,s;
	printf("Enter the desired number of elements: ");
	scanf("%d",&n);
	printf("Enter the first element: ");
	scanf("%d",&a);
	l=a;
	s=a;
	while(i<(n-1))
	{
	printf("Enter next element: ");
	scanf("%d",&a);
		
		if(a>l)
		{
		l=a;
		i+=1;
		}
		else
		{
		s=a;
		i+=1;
		}
	
	}
	
	printf("The largest number is : %d\n",l);
	printf("The smallest number is: %d\n",s);
}
	
