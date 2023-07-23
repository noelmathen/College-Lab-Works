#include<stdio.h>
int main()
{
  ifor(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[min]<a[j])
      {
        min=j;
      }
    }
    temp=a[i];
    a[i]=a[min];
    a[min]=temp;
  }
}