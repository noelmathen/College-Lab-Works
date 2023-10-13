#include<iostream>
using namespace std;

class Student{
	public:
			int Rno;
			float M1, M2;
			
			void getStudentData()
			{
				cout<<"\nEnter roll number: ";
				cin>>Rno;
				cout<<"Enter Mark 1: ";
				cin>>M1;
				cout<<"Enter Mark 2: ";
				cin>>M2;
			}
};

class Sport{
	public:
			float graceMarks;
			
			void getSportsData()
			{
				cout<<"Enter grace marks: ";
				cin>>graceMarks;
			}
};

class Report : public Student, public Sport{
	public:
			float total, avg;
			void calculate()
			{
				total=M1+M2+graceMarks;
				avg=total/3;
			}
			void displayReport()
			{
				cout<<"\nREPORT:-";
				cout<<"\nRoll number: "<<Rno;
				cout<<"\nMark 1: "<<M1;
				cout<<"\nMark 2: "<<M2;
				cout<<"\nGrace Marks: "<<graceMarks;
				cout<<"\nTotal: "<<total;
				cout<<"\nAvg: "<<avg;
			}	
};

int main()
{
	Report stud1;
	stud1.getStudentData();
	stud1.getSportsData();
	stud1.calculate();
	stud1.displayReport();
	cout<<"\n";
}
