#include<stdio.h>
void main()
{
    int a, x, n, f=1, i;
    printf("Enter any number: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    printf("%d",f);