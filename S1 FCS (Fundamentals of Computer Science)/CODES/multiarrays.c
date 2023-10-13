/* Multidimentional 3*3 matrix array */
#include<stdio.h>
#include<stdlib.h>
void main()
{
		int a[3][3];
		int i, j;
		printf("Enter matrix: \n\n");
		for(i=0;i<3;i++)
		{
			printf("Enter elements of row %d: \n",i+1);
			for(j=0;j<3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		printf("\n");
        printf("The matrix is: ");

		for(i=0;i<3;i++)
		{
			printf("\n");
			for(j=0;j<3;j++)
			{
				printf("%d\t",a[i][j]);
			}
		}
	printf("\n");
}