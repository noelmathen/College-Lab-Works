/* Program to read and display 3*3 matrix using pointers */
#include<stdio.h>
void main()
{
    int i,j;
    int *p;
    int a[3][3];
    for(j=0;j<3;j++)
    {
      printf("Enter the elements of row %d: \n",j+1);
      for(i=0;i<3;i++)
      {
        scanf("%d",&a[i][j]);
      }
    }
    p=&a;
    printf("\n\nThe Matrix is: \n");
    for(j=0;j<3;j++)
    {
      printf("\n");
      for(i=0;i<3;i++)
      {
        printf("%d ",(*p+j * 3+i));
      }
    }
    printf("\n");
}