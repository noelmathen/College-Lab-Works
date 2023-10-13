/* To generate a fibonacci series for a given level */
#include<stdio.h>
void main()
{
	int i, j, n=5, temp[100];
	int a[100];
	for(i=0;i<n;i++)
	{
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp[j]=a[j];
        a[j]=a[j+1];
        a[j+1]=temp[j];
      }
    }
  }

  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}
