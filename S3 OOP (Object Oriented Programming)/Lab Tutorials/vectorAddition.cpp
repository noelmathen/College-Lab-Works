#include<iostream>
using namespace std;

class vector{
	public:
			int x[3];
			vector()
			{
				x[0]=0;
				x[1]=0;
				x[2]=0;								
			}
			
			vector(int a)
			{
				x[0]=a;
				x[1]=0;
				x[2]=0;
			}
			
			vector(int a, int b)
			{
				x[0]=a;
				x[1]=b;
				x[2]=0;
			}
			
			vector(int a, int b, int c)
			{
				x[0]=a;
				x[1]=b;
				x[2]=c;
			}
			
			vector addvector(vector a, vector b)
			{
				vector c;
				c.x[0]=a.x[0]+b.x[0];
				c.x[1]=a.x[1]+b.x[1];
				c.x[2]=a.x[2]+b.x[2];
				return c;
			}
			
			void display()
			{
				cout<<x[0]<<", "<<x[1]<<", "<<x[2];
			}
			
			~vector()
			{
				
			}

};

int main()
{
	vector v3;
	vector v1(1,2,3);
	vector v2(3,4,5);
	
	cout<<"The first vector is: ";
	v1.display();
	cout<<"\nThe second vector is: ";
	v2.display();
	v3=v3.addvector(v1,v2);
	cout<<"\nThe vector sum is: ";
	v3.display();
	cout<<"\n";
}
