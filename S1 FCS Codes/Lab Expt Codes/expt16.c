/* To find the LCM of three numbers */
#include<stdio.h>
void main()
{
	int a, b, c, n=2, i=0;
	printf("Enter the first number  : ");
	scanf("%d",&a);
	printf("Enter the second number : ");
	scanf("%d",&b);
	printf("Enter the third number  : ");
	scanf("%d",&c);
	while(i==0)
	{
		if(n%a==0 && n%b==0 && n%c==0)
		{
		 i=n;
		}
		n+=1;
	}
	printf("The LCM is: %d\n",i);
}

