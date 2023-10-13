#include<stdio.h>


int DECtoBIN(int l)
{
    int n=0,m, i;
    for(i=1;i>0;i=i*10)
    {
    
      m=l%2;
      n=n+(m*i);
      l=l/2;
    }
    return n;
}


void main()
{
  int d, e, f;
              printf("Enter DECIMAL: ");
              scanf("%d",&d);
              f=DECtoBIN(d);
              printf("The BINARY equivalent is: %d",f);

}