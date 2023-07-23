#include<stdio.h>
int fact(int x)
{
	int f=1,i;
	for(i=1;i<=x;i++)
    {
        f=f*i;
    }
	return f;
}
void main()
{
    int a, n, f=1, i;
    printf("Enter any number: ");
    scanf("%d",&n);
	a=fact(n);
	printf("%d",a);

}
