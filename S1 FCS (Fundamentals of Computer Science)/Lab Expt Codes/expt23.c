/* To build a simple calculator to perform the following functions:-
1.x+y, 2.x-y, 3.x*y, 4.x/y, 5.x%y, 6.Square(x), 7.Sqrt(x), 8.x^y, 9.1/x, 10.x!, 11.$ to Rs, 12.Rs. To $, 13.DEC2BIN, 14.DEC2OCT 15:Exit */

#include<stdio.h>
#include<math.h>
void main()
{
	int  a, b, c, z, i, bin;
	float d, e, f;
	printf("\n");
	printf("MENU DRIVEN CALCULATOR\n\n");
	printf("Available operations:-\n 1.x+y\n 2.x-y\n 3.x*y\n 4.x/y\n 5.x%%y\n 6.Square(x)\n 7.Sqrt(x)\n 8.x^y\n 9.1/x\n 10.x!\n 11.$ to Rs\n 12.Rs. To $\n 13.DEC2BIN\n 14.DEC2OCT\n 15:Exit\n\n");
	
	printf("Enter your choice: ");
	scanf("%d",&z);

  do
  {
	if(z==1)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 printf("Enter y: ");
	 scanf("%f",&e);
	 f=d+e;
	 printf("%0.2f + %0.2f = %0.2f\n",d,e,f);
	}
	
	else if(z==2)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 printf("Enter y: ");
	 scanf("%f",&e);
	 f=d-e;
	 printf("%0.2f - %0.2f = %0.2f\n",d,e,f);
	}
	
	else if(z==3)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 printf("Enter y: ");
	 scanf("%f",&e);
	 f=d*e;
	 printf("%0.2f * %0.2f = %0.2f\n",d,e,f);
	}

	else if(z==4)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 printf("Enter y: ");
	 scanf("%f",&e);
	 f=d/e;
	 printf("%0.2f / %0.2f = %0.2f\n",d,e,f);
	}
	
	else if(z==5)
	{
	 printf("Enter x: ");
	 scanf("%d",&a);
	 printf("Enter y: ");
	 scanf("%d",&b);
	 c=a%b;
	 printf("%d %% %d = %d\n",a,b,c);
	}
	
	else if(z==6)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 f=d*d;
	 printf("square(%0.2f) = %0.2f\n",d,f);
	}
	
	else if(z==7)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 f=sqrt(d);
	 printf("sqrt(%0.2f) = %0.2f\n",d,f);
	}
	
	else if(z==8)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 printf("Enter y: ");
	 scanf("%f",&e);
	 f=pow(d,e);
	 printf("%0.2f ^ %0.2f = %0.2f\n",d,e,f);
	}
	
	else if(z==9)
	{
	 printf("Enter x: ");
	 scanf("%f",&d);
	 f=1/d;
	 printf("1 / %0.2f = %0.2f\n",d,f);
	}
	
	else if(z==10)
        {
	 printf("Enter x: ");
	 scanf("%d",&a);
	 c=1;
	 i=1;
	   while(i<a)
	    {
	     c=c*(i+1);
	     i++;
	    }
	 printf("%d!=%d\n",a,c);
	}
	
	else if(z==11)
	{
	 printf("Enter $: ");
	 scanf("%f",&e);
	 f=e*74.47;
	 printf("%0.2f$ = %0.2f Rs.\n",e,f);
	}
	
	else if(z==12)
	{
	 printf("Enter Rs: ");
	 scanf("%f",&e);
	 f=e/74.47;
	 printf("%0.2f Rs = %0.2f$\n",e,f);
	}
	
	else if(z==13)
	{
	 i=1;
	 bin=0;
	 printf("Enter the DECIMAL: ");
	 scanf("%d",&a);
	  while(a>0)
	  {
	   b=a%2;
	   bin=bin+b*i;
	   a=a/2;
	   i=i*10;
	  }
	printf("The BINARY equivalent is: %d\n",bin);  
	}
	
	else if(z==14)
	{
	 i=1;
	 bin=0;
	 printf("Enter the DECIMAL: ");
	 scanf("%d",&a);
	  while(a>0)
	  {
	   b=a%8;
	   bin=bin+b*i;
	   a=a/8;
	   i=i*10;
	  }
	printf("The OCTAL equivalent is: %d\n",bin);  
	}
	
	else if(z==15)
	{
	 break;
	}

	else
	{
	printf("INVALID OPERATION!\n");
	}
	
  	printf("\n");
	printf("Enter your choice: ");
	scanf("%d",&z);
	
  }
	while(a!=15);
}

