#include<iostream>
using namespace std;

class scalar{
	public:
			int x[3];
			
			scalar()
			{
				x[0]=0;
				x[1]=0;
				x[2]=0;								
			}
			
			scalar(int a)
			{
				x[0]=a;
				x[1]=0;
				x[2]=0;
			}
			
			scalar(int a, int b)
			{
				x[0]=a;
				x[1]=b;
				x[2]=0;
			}
			
			scalar(int a, int b, int c)
			{
				x[0]=a;
				x[1]=b;
				x[2]=c;
			}
			
			scalar scalarMul(int n, scalar a)
			{
				scalar b;
				b.x[0]=n*a.x[0];
				b.x[1]=n*a.x[1];
				b.x[2]=n*a.x[2];
				return b;
			}
			
			void display()
			{
				cout<<x[0]<<", "<<x[1]<<", "<<x[2];
			}
			
			~scalar()
			{
				
			}

};

int main()
{
	scalar v2;
	scalar v1(1,2);
	int num=2;
	cout<<"The vector is: ";
	v1.display();
	cout<<"\nThe scalar element is: "<<num;
	
	v2=v2.scalarMul(num,v1);
	cout<<"\nThe scalar multiplication is: ";
	v2.display();
	cout<<"\n";
}
