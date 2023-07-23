#include<iostream>
using namespace std;

class shape{
	public:
		int num;
		virtual void numberofSides()=0;
};

class rectangle : public shape{
	public:
		rectangle()
		{
			num=4;
		}
		void numberofSides()
		{
			cout<<"\nNumber of sides in a rectangle is: "<<num;
		}
};

class triangle : public shape{
	public:
		triangle()
		{
			num=3;
		}
		void numberofSides()
		{
			cout<<"\nNumber of sides in a triangle is: "<<num;
		}
};

class hexagon : public shape{
	public:
		hexagon()
		{
			num=6;
		}
		void numberofSides()
		{
			cout<<"\nNumber of sides in a hexagon is: "<<num;
		}
};

int main()
{
	rectangle r;
	triangle t;
	hexagon h;
	t.numberofSides();
	r.numberofSides();
	h.numberofSides();
	cout<<endl;
}

