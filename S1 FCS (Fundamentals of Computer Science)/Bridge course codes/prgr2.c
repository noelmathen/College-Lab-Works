/* To copy one array to another using pointers */
#include<stdio.h>
void main()
{
  int n, i, *p;
  int a[n], b[n];
  printf("Enter the number of elements of the array: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter element: ");
    scanf("%d",&a[i]);
  }
  p=a;
  for(i=0;i<n;i++)
  {
    *(b+i) = *(a+i);
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",b[i]);
  }
}
