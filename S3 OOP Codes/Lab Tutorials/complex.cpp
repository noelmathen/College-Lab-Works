#include<iostream>
using namespace std;
class complex{
	public:
			int real;
			int imag;
			void getdata()
			{
				cout<<"Enter the real part: ";
				cin>>real;
				cout<<"Enter the imaginary part:";
				cin>>imag;
			}
			
			void putdata()
			{
				cout<<"The complex number is: "<<real<<" + "<<imag<<"i";
				
			}
			
			complex add(complex x, complex y, complex z)
			{
				complex w;
				w.real = x.real + y.real + z.real;
				w.imag = x.imag + y.imag + z.imag;
				return w;
			}
			
			complex subtract(complex x, complex y)
			{
				complex z;
				z.real = x.real - y.real;
				z.imag = x.imag - y.imag;
				return z;
			}
};

int main()
{
	complex add1,add2,add3,sum,sub1,sub2,diff;
	cout<<"ADDITION: \n";
	cout<<"\n1st number for addition: \n";
	add1.getdata();
	cout<<"\n2nd number for addition: \n";
	add2.getdata();
	cout<<"\n3rd number for addition: \n";
	add3.getdata();
	sum=sum.add(add1,add2,add3);
	cout<<"\nTHE SUM IS: \n\n";
	sum.putdata();
	cout<<"\n";
	
	cout<<"\nSUBTRACTION: \n";
	cout<<"\n1st number for subtraction: \n";
	sub1.getdata();
	cout<<"\n2nd number for subtraction: \n";
	sub2.getdata();
	diff=diff.subtract(sub1,sub2);
	cout<<"\nTHE DIFFERENCE IS: \n\n";
	diff.putdata();
	cout<<"\n";
}




