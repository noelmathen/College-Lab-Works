/* Write a C program to Sort a list of strings in Ascending order */
#include <stdio.h>
#include<string.h>

# define num_string 4
void main ()
{	
	char temp[30];
	char  a[num_string][10];
	printf("Enter the strings:");
	for (int i=0;i<num_string;i++)
	{
		scanf("%s", a[i]);
	}
	printf("The elements of the array are :\n");
	for (int i=0;i<=3;i++)
	{
		printf("%s \n",a[i]);
		
	}
	printf("\n");
	
	/* sorting */
	
	for (int i=0; i<num_string;i++)
	{
		for (int j=0;j<num_string-1;j++)
		{
			if (strcmp(a[j],a[j+1])<0)
			{
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
	printf("The sorted string is :\n");
	for (int i=0;i<num_string;i++)
	{
		printf("%s \t",a[i]);
	}
					
	printf("\n");
	printf("Thankyou !");
	printf("\n");
}
		

