/* To generate the following series to a given level(1,8,27,64.......) */
#include<stdio.h>
void main()
{
	int n,i=1,a;
	printf("Enter the desired number of levels: ");
	scanf("%d",&n);
	while(i<=n)
	{
	a=i*i*i;
	printf("%d\n",a);
	i=i+1;
	}
}
