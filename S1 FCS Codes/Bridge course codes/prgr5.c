#include<stdio.h>
void series(int a)
{
    int i,fac=1,n,num;
    for(i=0;i<=n;i++)
    {
        fac=fac*i;
    }
    for(i=0;i<n;i++)
    {
        num=fac/n;
    }
}

void main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    series(x);
}