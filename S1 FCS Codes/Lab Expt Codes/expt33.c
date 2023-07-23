/* Checking symmetric matrix */
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, n, m, z, c=0;
    printf("Enter number of rows    : ");
    scanf("%d",&n);
    printf("Enter number of coloumns: ");
    scanf("%d",&m);
    int a[n][m];
    for(i=0;i<n;i++)
    {
      printf("Enter elements of row %d: \n",i+1);
      for(j=0;j<m;j++)
      {
        scanf("%d",&a[i][j]);
      }
    }
    printf("\n");
    printf("The input matrix is: \n");
    for(i=0;i<n;i++)
    {
      printf("\n");
      for(j=0;j<m;j++)
      {
        printf("%d\t",a[i][j]);
      }
    }
    printf("\n\n");
    printf("The transpose of input matrix is: \n");
    for(i=0;i<n;i++)
    {
      printf("\n");
      for(j=0;j<m;j++)
      {
        printf("%d\t",a[j][i]);
 		  	if(a[j][i]!=a[i][j])
 		  	{
 		  		c++;
 		  	}
 		  }
		}
		if(c==0)
		{
			printf("\n\nThe matrix is symmetric!\n");
		}
		else
		{
			printf("\n\nThe matrix is not symmetric!\n");			
		}
}
