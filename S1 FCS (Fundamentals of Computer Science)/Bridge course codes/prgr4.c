/* to print all perfect numbers in as given range using functions */
#include<stdio.h>
void perfect(int x, int y)
{
  int i, j;
  for(j=x+1;j<y;j++)
  {
    int sum=0;
    for(i=1;i<j;i++)
    {
        if(j%i==0)
        {
            sum = sum + i;
        }
    }
    if(sum==j)
    {
      printf("%d, ",j );
    }
  }
}

void main()
{
  int a, b;
  printf("Enter the lower limit: ");
  scanf("%d",&a);
  printf("Enter the upper limit: ");
  scanf("%d",&b);
  perfect(a,b);
  

}