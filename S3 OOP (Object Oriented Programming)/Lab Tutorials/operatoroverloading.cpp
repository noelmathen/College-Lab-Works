#include<iostream>
#include<stdlib.h>
using namespace std;

class complex{
	public:
			float real, imag;
			complex(int x, int y)
			{
				real=x;
				imag=y;	
			}
			
			complex(){}
			
			void printComplex()
			{
				cout<<"The complex number is: "<<real<<" + "<<imag<<"i"; 
			}
			
			complex operator + (complex const &obj)
			{
				complex result;
				result.real = this->real + obj.real;
				result.imag = this->imag + obj.imag;
				return result;			
			}
			
			complex operator - (complex const &obj)
			{
				complex result;
				result.real = real - obj.real;
				result.imag = imag - obj.imag;
				return result;			
			}

			complex operator * (complex const &obj)
			{
				complex result;
				result.real=(real*obj.real)-(imag*obj.imag);
				result.imag=(real*obj.imag)+(imag*obj.real);
				return result;
			}
			
			complex operator / (complex const &obj)
			{
				complex result;
				result.real=((real*obj.real)+(imag*obj.imag)) / ((obj.real*obj.real)+(obj.imag*obj.imag));
				result.imag=((imag*obj.real)-(real*obj.imag)) / ((obj.real*obj.real)+(obj.imag*obj.imag));
				return result;
			}
};

int main()
{
	int ch;
	complex a(3,3);
	complex b(2,2);
	complex c;
	c=a+b;
	cout<<"OPERATOR OVERLOADING FOR COMPLEX NUMBERS!\n";
	cout<<"MENU:-\n1. ADD\n2. SUBTRACT\n3. MULTIPLY\n4. DIDIVDE\n5. EXIT";
	while(1)
	{
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		if(ch==1)
		{
			c=a+b;
			c.printComplex();
		}
		else if(ch==2)
		{
			c=a-b;
			c.printComplex();
		}
		else if(ch==3)
		{
			c=a*b;
			c.printComplex();
		}
		else if(ch==4)
		{
			c=a/b;
			c.printComplex();
		}
		else if(ch==5)
		{
			cout<<"OHK BEI:))\n";
			exit(0);
		}
		else
		{
			cout<<"INVALID CHOICE!";
		}
	}
	
}

