#include<iostream>
using namespace std;

class car{
	private:
			int litre;
			double consumption;
				
	public:
			car()
			{
				litre=40;
				consumption=0.1;
				cout<<"\nThe car with the given features has been created(default)!";
			}
			
			car(int x,int y)
			{
				litre=x;
				consumption=y;
				cout<<"\nThe car with the given features has been created(parameterized)!\n";
			}
			
			double maxDistance()
			{
				double maxdis=litre/consumption;
				return maxdis;
			}
			
			void display()
			{
				cout<<"\nThe value of litre is: "<<litre;
				cout<<"\nThe value of consumption is: "<<consumption;
			}
			
			~car()
			{
				cout<<"\n\nThe car with the given features has been destructed!\n";
			}
			
};

int main()
{
	int a, b, d;
	car c1;
	c1.display();
	cout<<"\n\nEnter litre: ";
	cin>>a;
	cout<<"Enter consumption: ";
	cin>>b;
	car c2(a,b);
	c2.display();
	d=c2.maxDistance();
	cout<<"\nThe maximum distance is: "<<d;
	
}

