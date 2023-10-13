/* Program to read and display 3*3 matrix using pointers */
#include<stdio.h>
void main()
{
    int i,j;
    int *p;
    int a[3][3];
    for(i=0;i<3;i++)
    {
      printf("Enter the elements of row %d: ",i+1);
      for(j=0;j<3;j++)
      {
        scanf("%d",&a[i][j]);
      }
    }
    p=&a[i][j];
    printf("\n\nThe Matrix is: \n");
    for(i=0;i<3;i++)
    {
      printf("\n");
      for(j=0;j<3;j++)
      {
        printf("%d ",(*(p+i) * 3+j));
      }
    }
    printf("\n");
}

