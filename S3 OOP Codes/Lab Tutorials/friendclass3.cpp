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
				cout<<"\nRoll No: "<<Rno;
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
				cout<<"\nEnter Mark 1: ";
				cin>>val.m1;
				cout<<"Enter Mark 2: ";
				cin>>val.m2;
				val.total=val.m1+val.m2;
			}
};

int main()
{
	int n, i;
	cout<<"Enter the number of students(less than 10): ";
	cin>>n;
	student stud[n];
	teacher binu;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter details of student "<<i+1<<":-";
		binu.enterMarks(stud[i]);
	}
	for(i=0;i<n;i++)
	{
		cout<<"\n\nDetails of student "<<i+1<<":-";
		stud[i].display();
	}
	cout<<"\n";
}

