#include<iostream>
using namespace std;
class point{
	private:	
		int x, y;
	public:
		point()
		{
			x=0;
			y=0;
		}
		point( int a, int b)
		{
			x=a;
			y=b;
		}
		void setx(int a)
		{
			x=a;
		}
		void sety(int a)
		{
			y=a;
		}
		void setxy(int a, int b)
		{
			x=a;
			y=b;
		}
		void sum(int a, int b)
		{
			int s=a+b;
			cout<<"Sum is: "<<s;
		}
		void sums(int a)
		{
			x=a;
			int n, s=0, d;
			n=x/y;
			while (n!=0)
			{
				d=n%10;
				s=s+d;
				n=n/10;
			}
			cout<<s;
		}
		void display()
		{
			cout<<x<<"\t"<<y;
		}
};

int main()
{
	point p;
	int a, b;
	point p1(2,3);
	p.display();
	cout<<"\nEnter value of x: ";
	cin>>a;
	p.setx(a);
	p.display();
	cout<<"\nEnter value of y: ";
	cin>>a;
	p.sety(a);
	p.display();
	cout<<"\nEnter value of x and y: ";
	cin>>a;
	cin>>b;
	p.sum(a,b);
	cout<<"\nEnter value of x: ";
	cin>>a;
	p.sums(a);
}


