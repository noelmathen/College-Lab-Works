/* Matrix Multiplication */
#include<stdio.h>
void main()
{
    int i, j, n, m, k, l;
    printf("\nEnter matrix A : \n\n");
    printf("Enter number of rows    : ");
    scanf("%d",&n);
    printf("Enter number of coloumns: ");
    scanf("%d",&m);
    int a[n][m];
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("Enter elements of row %d: \n",i+1);
      for(j=0;j<m;j++)
      {
        scanf("%d",&a[i][j]);
      }
    }
    printf("\n");
    
    printf("\nEnter matrix B: \n\n");
    printf("Enter number of rows    : ");
    scanf("%d",&k);
    printf("Enter number of coloumns: ");
    scanf("%d",&l);
    int b[k][l];
    printf("\n");
    for(i=0;i<k;i++)
    {
      printf("Enter elements of row %d: \n",i+1);
      for(j=0;j<l;j++)
      {
        scanf("%d",&b[i][j]);
      }
    }
    printf("\n");
    
    printf("Matrix A is: \n");
    for(i=0;i<n;i++)
    {
      printf("\n");
      for(j=0;j<m;j++)
      {
        printf("%d   ",a[i][j]);
      }
    }
    printf("\n\n");
    
    printf("Matrix B is: \n");
    for(i=0;i<k;i++)
    {
      printf("\n");
      for(j=0;j<l;j++)
      {
        printf("%d   ",b[i][j]);
      }
    }
    int c[i][j];
    printf("\n\n Matrix C = A * B = \n");
    
    for(i=0;i<n;i++)
    {
    	printf("\n");
    	for(j=0;j<m;j++)
    	{
    		c[i][j]=0;
    		for(k=0;k<m;k++)
    		{
    	  	c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
    		}	
    		
    		printf("%d   ",c[i][j]);
    	}
    }
    
    printf("\n\n");		
}
