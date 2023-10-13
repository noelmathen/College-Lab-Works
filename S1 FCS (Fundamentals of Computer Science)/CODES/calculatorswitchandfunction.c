/* Implement a menu driven calculator using switch and functions */
#include<stdio.h>
#include<math.h>

float sum(float x,float y)     //addition
{
    float z=x+y;
    return z;
}
float sub(float x,float y)     //subtraction
{
    float z=x-y;
    return z;
}
float mult(float x,float y)    //multiplication
{
    float z=x*y;
    return z;
}
float div(float x,float y)     //division
{
    float z=x/y;
    return z;
}
int moddiv(int l,int m)       //modulo division
{
    int n=l%m;
    return n;
}
float square(float x)         //square
{
    float z=x*x;
    return z;
}
float sqroot(float x)         //square eroot
{
    float z=sqrt(x);
    return z;
}
float power(float x,float y)  //power
{
    float z=pow(x,y);
    return z;
}
float inv(float x)            //reciprocal
{
    float z=1/x;
    return z;
}
int fact(int l)               //factorial
{
    int n=1,i;
    for(i=1;i<l;i++)
    {
      n=n*(i+1);
    }
    return n;
}
float _$toRs_(float x)        //$ to Rs
{
    float z=x*75.06;;
    return z;
}

float _Rsto$_(float x)        //Rs to $
{
    float z=x/75.06;;
    return z;
}
int DECtoBIN(int l)           //Decimal to binary
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
int DECtoOCT(int l)           //Binary to decimal
{
    int n=0,m, i;
    for(i=1;i>0;i=i*10)
    {
    
      m=l%8;
      n=n+(m*i);
      l=l/8;
    }
    return n;
}



void main()
{
  float a, b, c;
  int d, e, f;
  int q;
  printf("\n***MENU DRIVEN CALCULATOR USING SWITCH AND FUNCTIONS***\n");
  printf("\n*******************************************************\n\n");
  printf("Available operations:-\n 1.x+y\n 2.x-y\n 3.x*y\n 4.x/y\n 5.x%%y\n 6.Square(x)\n 7.Sqrt(x)\n 8.x^y\n 9.1/x\n 10.x!\n 11.$ to Rs\n 12.Rs. To $\n 13.DEC2BIN\n 14.DEC2OCT\n 15:Exit\n");
  printf("\nEnter your choice: ");
  scanf("%d",&q);
  printf("\n");
  do
  {
    switch (q)
    {
      case 1:{
              printf("Enter x: ");
              scanf("%f",&a);
              printf("Enter y: ");
              scanf("%f",&b);
              c=sum(a,b);
              printf("%.2f + %.2f = %.2f",a,b,c);
              break;
             }
      case 2:{
              printf("Enter x: ");
              scanf("%f",&a);
              printf("Enter y: ");
              scanf("%f",&b);
              c=sub(a,b);
              printf("%.2f - %.2f = %.2f",a,b,c);
              break;
             }
      case 3:{
              printf("Enter x: ");
              scanf("%f",&a);
              printf("Enter y: ");
              scanf("%f",&b);
              c=mult(a,b);
              printf("%.2f * %.2f = %.2f",a,b,c);
              break;
             }
      case 4:{
              printf("Enter x: ");
              scanf("%f",&a);
              printf("Enter y: ");
              scanf("%f",&b);
              c=div(a,b);
              printf("%.2f / %.2f = %.2f",a,b,c);
              break;
             }
      case 5:{
              printf("Enter x: ");
              scanf("%d",&d);
              printf("Enter y: ");
              scanf("%d",&e);
              f=moddiv(d,e);
              printf("%d %% %d = %d",d,e,f);
              break;
             }
      case 6:{
              printf("Enter x: ");
              scanf("%f",&a);
              c=square(a);
              printf("%.2f * %.2f = %.2f",a,a,c);
              break;
             }
      case 7:{
              printf("Enter x: ");
              scanf("%f",&a);
              c=sqroot(a);
              printf("sqrt(%.2f) = %.2f",a,c);
              break;
             }
      case 8:{
              printf("Enter x: ");
              scanf("%f",&a);
              printf("Enter y: ");
              scanf("%f",&b);
              c=power(a,b);
              printf("%.2f ^ %.2f = %.2f",a,b,c);
              break;
             }
      case 9:{
              printf("Enter x: ");
              scanf("%f",&a);
              c=inv(a);
              printf("1/%.2f = %.4f",a,c);
              break;
             }
     case 10:{
              printf("Enter x: ");
              scanf("%d",&d);
              f=fact(d);
              printf("%d! = %d",d,f);
              break;
             }
     case 11:{
	            printf("Enter $: ");
	            scanf("%f",&a);
	            c=_$toRs_(a);
	            printf("%.2f$ = %.2fRs.",a,c);
              break;
	            }
     case 12:{
	            printf("Enter Rs: ");
	            scanf("%f",&a);
	            c=_Rsto$_(a);
	            printf("%.2f$ = %.2fRs.",a,c);
              break;
	            }
      case 13:{
              printf("Enter DECIMAL: ");
              scanf("%d",&d);
              f=DECtoBIN(d);
              printf("The BINARY equivalent is: %d",f);
              break;
              }
      case 14:{
              printf("Enter OCTAL: ");
              scanf("%d",&d);
              f=DECtoOCT(d);
              printf("The OCTAL equivalent is: %d",f);
              break;
              }
      case 15:{
                break;
              }        
      default:{
                printf("INVALID INPUT!");
              }
    }
    printf("\n\nEnter your choice: ");
    scanf("%d",&q);
    printf("\n");
  }
  while(q!=15);
}