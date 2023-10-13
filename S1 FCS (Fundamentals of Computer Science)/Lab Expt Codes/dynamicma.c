#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p;
    int a, n, sum=0, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    p=(int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++)
    {
      printf("Enter the elemet: ");
      scanf("%d",p+i);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("%d ",*(p+i));
    }
    free(p);
}