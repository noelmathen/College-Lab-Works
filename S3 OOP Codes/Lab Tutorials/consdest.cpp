#include<iostream>
using namespace std;

class my_class{
		public:
				int a, b;
				
				my_class()
				{
					a=1;
					b=2;
					cout<<"\nExecuting Default Constructor!";
				}
				
				my_class(int x)
				{
					a=x;
					b=20;
					cout<<"\n\nExecuting Parameterized Constructor!";
				}
				
				my_class(int x, int y)
				{
					a=x;
					b=y;
					cout<<"\n\nExecuting Copy Constructor!\n";
				}
				
				void display()
				{
					cout<<"\nThe value of a is: "<<a;
					cout<<"\nThe value of b is: "<<b;
				}
				
				~my_class()
				{
					cout<<"\n\nDESTRUCTOR\n";
				}
							
};


int main()
{
	my_class obj1;
	obj1.display();
	my_class obj2(10);
	obj2.display();
	my_class obj3(100,300);
	obj3.display();
}


