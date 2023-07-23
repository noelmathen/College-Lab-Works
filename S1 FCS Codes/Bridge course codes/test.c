#include<stdio.h>
void main()
{
    int n=497,i, sum=0;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum = sum + i;
        }
    }

    if(sum==n)
    {
        printf("PERFECT;");
    }
    else
    {
        printf("NOT PERFECT");
    }
}