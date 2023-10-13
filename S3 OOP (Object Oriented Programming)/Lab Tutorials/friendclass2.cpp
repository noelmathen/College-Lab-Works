#include<iostream>
using namespace std;
static int count=1;
class student{
	private:
			int Rno;
			float m1, m2, total;
	public:
			student()
			{
				Rno=count++;
			}
				
			void display()
			{
				cout<<"\n\nRoll No: "<<Rno;
				cout<<"\nMark 1: "<<m1;
				cout<<"\nMark 2: "<<m2;
				cout<<"\nTotal Mark: "<<total;
			}
			friend class teacher;
};

class teacher{
	public:
			void enterMarks(student &val)
			{
				cout<<"Enter Mark 1: ";
				cin>>val.m1;
				cout<<"Enter Mark 2: ";
				cin>>val.m2;
				val.total=val.m1+val.m2;
			}
};

int main()
{
	student noel;
	teacher binu;
	binu.enterMarks(noel);
	noel.display();
	cout<<"\n";
}

